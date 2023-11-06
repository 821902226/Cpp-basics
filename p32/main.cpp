 #include <iostream>
 #include <ctime>
  
 using namespace std;

//猜数字游戏，生成一个0~100的随机数，提示用户猜的数字过大还是过小。
 int main()
 {
    int num, guess;
    //生成随机种子
    srand(time(0));
    //生成随机数-------------rand()范围是0~32767
    num = rand()%101;

    //cout<<"当前数字为: "<<num<<endl;
    cout<<"猜数字：";
    cin>>guess;
    while (guess!=num)
    {
        if (guess>num)
        {
            cout<<"数字太大！！！"<<endl;
        }
        else
        {
            cout<<"数字太小！！！"<<endl;
        }
        cout<<"请重新输入：";
        cin>>guess;
    }
    cout<<"恭喜你，猜对了！！！"<<endl;

    system("pause");
    return 0;

 }