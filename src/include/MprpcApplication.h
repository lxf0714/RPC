#pragma once
 
//mprpc框架的基础类  单例模式 负责初始化
 class MprpcApplication
 {
  public:
    // 初始化操作
    static void Init(int argc, char** argv);
    static MprpcApplication& GetInstance();

  private:
    MprpcApplication();
    MprpcApplication(const MprpcApplication&) = delete; // 禁止拷贝构造
    MprpcApplication& operator=(const MprpcApplication&) = delete;// 禁止赋值构造
    MprpcApplication(MprpcApplication&&) = delete;// 禁止移动构造

 };