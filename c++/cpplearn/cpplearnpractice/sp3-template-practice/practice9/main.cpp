#include "TypeIdentity.h"

int main() {
    // 2. ʹ�� static_assert �� std::is_same ��֤
    
    // ��� TypeIdentity<int>::type �Ƿ��� int ��ͬһ����
    static_assert(std::is_same<TypeIdentity<int>::type, int>::value, 
                  "TypeIdentity<int>::type �����ͬ�� int");
    
    // ��� TypeIdentity<double>::type �Ƿ��� double ��ͬһ����
    static_assert(std::is_same<TypeIdentity<double>::type, double>::value, 
                  "TypeIdentity<double>::type �����ͬ�� double");

    // ����ʱ���ͼ�飬�������� assert ��ͨ�������뽫����ʧ�ܲ���ʾ������Ϣ
    // static_assert(std::is_same<TypeIdentity<float>::type, int>::value, 
    //               "����һ������ļ�飬����Ӧ���޷�ͨ������"); 

    std::cout << "TypeIdentity ��֤ͨ�����������͹�ϵ�ڱ���ʱȷ������" << std::endl;

    return 0;
}