#include <iostream>
#include<string>
#include "test.pb.h"

using namespace fixbug;

int main()
{
    getlist get;
    user* u1 = get.add_friend_list();
    u1->set_name("zhangsan");
    u1->set_age(18);
    user* u2 = get.add_friend_list();
    u2->set_name("lisi");
    u2->set_age(20);
    std::cout<<get.friend_list_size()<<std::endl;
    for(int i=0; i<get.friend_list_size(); i++)
    {
      user u = get.friend_list(i);
      std::cout<<"name:"<<u.name()<<std::endl;
      std::cout<<"age:"<<u.age()<<std::endl;
    }
    return 0;
}
int main1()
{
    LoginRequest req;
    req.set_name("zhangsan");
    req.set_pwd("123456");

    std::string send_str;
    if(req.SerializeToString(&send_str))
    {
        std::cout<<send_str<<std::endl;
    }
    //反序列化
    LoginRequest req2;
    if(req2.ParseFromString(send_str))
    {
        std::cout<<"name:"<<req2.name()<<std::endl;
        std::cout<<"pwd:"<<req2.pwd()<<std::endl;
    }
    return 0;
}
// 编译 
//g++ test.pb.cc main.cc -o main -L/usr/local/lib -lprotobuf 