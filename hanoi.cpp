    #include <iostream>
    using namespace std;

    void hanoi(int, char, char, char) ;

    int cnt =0 ;

    int main(){
        int n;
        cout << "河內塔(Tower of Hanoi) \n 請輸入有幾個金盤 => ";
        cin >> n;
        hanoi(n, 'A', 'B', 'C');
        cout <<"總共"<<cnt<<"次";
        return 0;
    }


    void hanoi(int n, char from, char temp, char dest){

        if(n==1){
            cout << "移動金盤 1 從 " << from << " 到 " << dest << "\n";
            cnt ++;
        }
        else{
            hanoi(n-1,from,dest,temp);

            cout << "移動金盤 "<< n <<" 從 "<< from << " 到 " << dest << "\n";
            cnt++;

            hanoi(n-1,temp,from,dest);
    }

    } 

