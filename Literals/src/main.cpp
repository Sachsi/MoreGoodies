#include <iostream>

//an operator functionfor literals is created by OPERATOR""_<öiteral>
//return type can be any type including void
//Literal operator functions cannot be member, only global functions
class Distance
{// Class save the value alwayse in kilometer
private:
    long double m_Kilometres;
public:
    Distance(long double km) : m_Kilometres{km}{

    }
    long double GetKm() const {
        return m_Kilometres;
    }
    void SetKm(long double val){
        m_Kilometres = val;
    }
    ~Distance(){

    }

};

Distance operator"" _mi(long double val){
    return Distance{val * 1.6};
}
Distance operator"" _metres(long double val){
    return Distance{val / 1000};
}

void Literal(void){
    Distance dist{32.0_mi}; //this value is in miles 
    Distance d2{3498.0_metres}; // this value is in metres
    std::cout << "in Kilometer: " << d2.GetKm() << std::endl;
    std::cout << "in Kilometer: " << dist.GetKm() << std::endl;
}

int GetNumber(){
    return 23;
}
constexpr int GetExPrNumber(){
    return 23;
}
constexpr int Max(int x, int y){
    if(x > y)
        return x;
    return y;
    //return x > y ? x : y;
}

int main(void){
    
    Literal();
    //constexpr, the value is computate at compile time
    constexpr int i = 10; //GetNumber() is not possible, because returning value at run time
    constexpr int h = Max(5,6); //GetExPrNumber() is possible, because returning value is computate at compile time

    int arr[i]; // can use it for the size of array
    //Behaves as normal function
    const int j = GetNumber(); //GetNumber can use at Compile time -> so j is not computate at compile time
    //Behaves as constexpr function
    const int y = GetExPrNumber();
    //Behaves as normal function
    int x = GetExPrNumber();
    //int arr1[j];    // can use one const int as well but is not always computate at compile time
    return 0;
}
/*Constant expression function rules
1. Should accept and return literal types only (void, scalar types(int, float, char) references, etc...)
2. Should contain only single line statement that should be a return statement
3. constexpr functions are implicitly inline (write in header files)*/