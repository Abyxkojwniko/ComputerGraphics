import os
import json
import smtplib
from datetime import datetime
from email.mime.text import MIMEText

# --- 飞牛OS & 路径配置 ---
SOURCE_FOLDER = "/vol1/1000/Learn/acwing" 
DATA_FILE = os.path.join(SOURCE_FOLDER, "study_progress.json")

# --- 163 邮箱配置 ---
SMTP_SERVER = "smtp.163.com"
SMTP_PORT = 465
MAIL_USER = "abyxkojw@163.com"
MAIL_PASS = "DFL7T6ZmJAFkJb6B" 

# --- 记忆策略配置 (已调整为 2+1 模式) ---
INTERVALS = [1, 2, 4, 7, 15, 30]
REVIEW_LIMIT = 2  # 每日复习上限 (2道)
NEW_LIMIT = 1     # 每日新题上限 (1道)

def update_and_get_tasks():
    # 1. 初始化/读取数据
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, 'r', encoding='utf-8') as f:
            data = json.load(f)
    else:
        data = {}

    today_dt = datetime.now()
    today_str = today_dt.strftime("%Y-%m-%d")
    
    # 2. 扫描文件夹，发现新代码
    current_files = [f for f in os.listdir(SOURCE_FOLDER) 
                     if f.endswith(".cpp") and f != "recall_engine.py"]
    
    for file in current_files:
        if file not in data:
            data[file] = {"start_date": None}

    # 3. 筛选【该复习】的旧题
    review_queue = []
    for file, info in data.items():
        if info["start_date"]:
            start_dt = datetime.strptime(info["start_date"], "%Y-%m-%d")
            diff_days = (today_dt - start_dt).days
            if diff_days in INTERVALS:
                # 记录这是第几次复习，增加成就感
                stage = INTERVALS.index(diff_days) + 1
                review_queue.append(f"🔄 旧题复习: {file} (阶段 {stage})")

    # 按照配额取前 2 道旧题
    review_queue.sort()
    tasks_review = review_queue[:REVIEW_LIMIT]

    # 4. 筛选【未激活】的新题并激活 1 道
    new_queue = [f for f, info in data.items() if info["start_date"] is None]
    new_queue.sort() 
    
    tasks_new = []
    for i in range(min(NEW_LIMIT, len(new_queue))):
        target_file = new_queue[i]
        data[target_file]["start_date"] = today_str
        tasks_new.append(f"✨ 新题激活: {target_file}")

    # 5. 保存进度
    with open(DATA_FILE, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=4)
        
    return tasks_review, tasks_new

def send_email(review_list, new_list):
    # 邮件内容构建
    total_count = len(review_list) + len(new_list)
    if total_count == 0:
        content = "今日无复习任务，文件夹中也没有待激活的新题。去休息一下吧！"
    else:
        content = f"✅ 今日算法精简清单 (2+1 模式，共 {total_count} 道)：\n\n"
        content += "---【旧题巩固】---\n" + ("\n".join(review_list) if review_list else "暂无到期旧题")
        content += "\n\n---【新题激活】---\n" + ("\n".join(new_list) if new_list else "今日无新题名额")
        content += "\n\n💡 慢就是快。每天搞透这几道题，比盲目刷题强得多。"

    msg = MIMEText(content, 'plain', 'utf-8')
    msg['Subject'] = f"【算法排队系统】{datetime.now().strftime('%m-%d')} 任务清单"
    msg['From'] = MAIL_USER
    msg['To'] = MAIL_USER

    try:
        server = smtplib.SMTP_SSL(SMTP_SERVER, SMTP_PORT)
        server.login(MAIL_USER, MAIL_PASS)
        server.sendmail(MAIL_USER, [MAIL_USER], msg.as_string())
        server.quit()
        print("邮件发送成功")
    except Exception as e:
        print(f"邮件发送失败: {e}")

if __name__ == "__main__":
    review_tasks, new_tasks = update_and_get_tasks()
    send_email(review_tasks, new_tasks)