#include <iostream>
#include <string>

using namespace std;

class Cube{
    private:
        float length, width, high;

    public:
        void setLength(float chang)
        {
            length = chang;
        }
        void setWidth(float kuan)
        {
            width = kuan;
        }
        void setHigh(float gao)
        {
            high = gao;
        }
        float getLength()
        {
            return length;
        }
        float getWidth()
        {
            return width;
        }
        float getHigh()
        {
            return high;
        }
        
        //计算表面积
        void calculateArea()
        {
            float area = length*width*2 + length*high*2 + width*high*2;
            cout<<"立方体的表面积是："<<area<<endl;
        }
        //计算体积
        void calculateVolume()
        {
            float volume = length*width*high;
            cout<<"立方体的体积是："<<volume<<endl;
        }

        void isSame(Cube &c)
        {
            if(c.getLength()==length && c.getWidth()==width && c.getHigh()==high)
            {
                cout<<"1:两个立方体相等。"<<endl;
            }
            else{
                cout<<"1:两个立方体不等。"<<endl;
            }
        }

};

void isSame(Cube &c1, Cube &c2)
{
    if (c1.getLength()==c2.getLength() && c1.getWidth()==c2.getWidth() && c1.getHigh()==c2.getHigh())
    {
        cout<<"2:两个立方体相等。"<<endl;
    }
    else{
        cout<<"2:两个立方体不等。"<<endl;
    }
}

int main()
{
    Cube c1, c2;
    c1.setLength(1);
    c1.setWidth(2);
    c1.setHigh(3);
    c1.calculateArea();
    c1.calculateVolume();

    c2.setLength(1);
    c2.setWidth(2);
    c2.setHigh(3);

    c1.isSame(c2);
    isSame(c1, c2);

}