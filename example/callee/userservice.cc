#include <iostream>
#include <string>
#include "user.pb.h"
#include "MprpcApplication.h"
#include "RpcProvider.h"

/*
userservice 原来是一个本地服务 提供了两个进程内的本地方法，Login和GetFriendList
 */
class UserService : public fixbug :: UserServiceRpc
{
public:
    bool login(std::string name, std::string pwd)
    {
      std::cout<< "doing local service login, name: " << name << ", pwd: " << pwd << std::endl;
      // 模拟登录成功
      return true;
    }
    /*
    重写基类UserServiceRpc的虚函数 下面这些方法都是框架调用的
    1. caller ==> login(loginRequest) ==> muduo ==> callee
    2. callee ==> login(loginRequest) ==> UserService::login(name, pwd)
     */
      virtual void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done)
      {
        // 1. 获取请求参数
        std::string name = request->name();
        std::string pwd = request->pwd();
        
        // 2. 调用本地服务
        bool login_result = login(name, pwd);

        // 3. 设置响应结果
        fixbug::Resultcode* code = response->mutable_result();
        code->set_errcode("0");
        code->set_errmsg("success");
        response->set_sucess(login_result);

        // 4. 执行回调
        if (done)
        {
          done->Run();
        }
      }

};
int main(int argc, char* argv[])
{
  // 调用框架的初始化操作
  MprpcApplication::Init(argc, argv);

  //provider是一个rpc网络服务对象 把UserService发布到rpc节点上
  RpcProvider provider;
  provider.NotifyService(new UserService());
  // 启动rpc服务 run以后 进程进入阻塞状态 等待远程的rpc调用
  provider.Run();


  return 0;
}