#include "MprpcApplication.h"

void MprpcApplication::Init(int argc, char** argv)
{

}     
MprpcApplication& MprpcApplication::GetInstance()
{
    static MprpcApplication app;
    return app;
}