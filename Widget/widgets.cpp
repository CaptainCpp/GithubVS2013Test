// #define _CRT_SECURE_NO_WARNINGS
// 
// #include <stdlib.h>
// #include <string>
 #include <vector>
 #include <iostream>



#if 0
int main()
{
    std::string fPath = "D:\\MySourse\\Test\\Image3D";
    std::string path;
    std::string fPathEnd = ".xml";
    char buffer[20];
    std::vector<std::string> vecFileName;
    for (int i = 0; i < 100; ++i)
    {
        _itoa(i, buffer, 10);
        std::string s(buffer);
        path = fPath + s + fPathEnd;
        vecFileName.push_back(path);
    }
    std::cout << vecFileName[0] << std::endl;
    return 0;
}
#endif

int main()
{
    char c = 128;
    char d = 129;
    printf("%d,%d\n", c, d);

    system("pause");
    return 0;
}