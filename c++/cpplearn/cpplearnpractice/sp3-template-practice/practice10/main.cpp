#include "TypeList.h"

int main() {
    std::cout << "--- ������ TypeList ���ȼ������ ---" << std::endl;

    // 1. ���Կ��б�
    using EmptyList = TypeList<>;
    static_assert(LengthOf<EmptyList>::value == 0, "���б���ӦΪ 0");
    std::cout << "���б���: " << LengthOf<EmptyList>::value << " (��֤ͨ��)" << std::endl;

    // 2. ���԰��� 3 �����͵��б�
    using List3 = TypeList<int, double, char>;
    static_assert(LengthOf<List3>::value == 3, "���� 3 �����͵��б���ӦΪ 3");
    std::cout << "List<int, double, char> ����: " << LengthOf<List3>::value << " (��֤ͨ��)" << std::endl;

    // 3. ���԰��� 5 �����͵ĸ����б�
    using List5 = TypeList<int, std::string, std::vector<int>, bool, long>;
    static_assert(LengthOf<List5>::value == 5, "���� 5 �����͵��б���ӦΪ 5");
    std::cout << "�����б���: " << LengthOf<List5>::value << " (��֤ͨ��)" << std::endl;
    
    // ��������Դ���һ���� TypeList �����ͣ����磺
    // static_assert(LengthOf<int>::value == 0, "Ӧʧ�ܣ���Ϊ int ���� TypeList"); 
    // ^ �⽫������ģ�� LengthOf<List> ��ʹ�ã�������ģ��û�� value ��Ա����ֱ�ӵ��±��������Ҳ����ȷ����ơ�

    std::cout << "\n���� LengthOf ���㶼�ڱ�������ɣ�������" << std::endl;

    return 0;
}