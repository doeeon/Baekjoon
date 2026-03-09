#include <iostream>

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    int T;

    cin >> T;

    

    for(int t=1; t<=T; t++)

    {

        int A, B;

        cin >> A >> B;

        

        cout << "Case #" << t << ": " << A+B << '\n';

    }

    return 0;

}