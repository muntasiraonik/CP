#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<pair<LL, LL>> VP;
typedef vector<VL> VV;

#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end());
#define pb push_back
#define F first
#define S second
#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define all(v) (v).begin(), (v).end()
#define no "NO"
#define stp setprecision
#define yes "YES"
#define con continue;
#define PI 2*acos(0)

const LL mod = 10000007;
const LL INF = 1e18;

LL lcm(LL a, LL b){return (a/__gcd(a,b))*b;}
LL sumN(LL x){return (x*(x+1))/2;}

LL sum1 = 0;
LL nxt(){LL x;cin >> x,sum1+=x;return x;}




LL zero(){return 0;}
LL binpow(LL a, LL b)
{
    LL res = 1 ;
    while(b > 0){
        if(b & 1)
        res = res * a;
        a = a * a  ;
        b >>= 1;
    }
    return res;
}

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}



LL ax[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
LL yx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

string multiplication(string n1, string n2)
{
    long long  size1 = n1.size();
    long long size2 = n2.size();
    
    if(size1==0 || size2==0)
        return "0";
    
    vector<long long> result(size1+size2, 0);
    
    LL n1_pos = 0;
    LL n2_pos = 0;
    
    long long i,j;
    for(i=size1-1; i>=0; i--)
    {
        long long carry = 0;
        long long digit1 = n1[i]-'0';
        
        n2_pos = 0;
        
        for(j=size2-1; j>=0; j--)
        {
            long long digit2 = n2[j]-'0';
            
            long long product = digit1 * digit2 + result[n1_pos+n2_pos] + carry;
            
            carry = product/10;
            
            result[n1_pos+n2_pos] = product % 10;
            
            n2_pos++;
        }
        
        if(carry>0)
            result[n1_pos+n2_pos] += carry;
            
        n1_pos++;
    }
    
    i = result.size()-1;
    while(i>=0 && result[i]==0)
        i--;
        
    if(i==-1)
        return "0";
        
    string ans = "";
    
    while(i>=0)
        ans += to_string(result[i--]);
        
    return ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL q=1,t;
    LL a=0,b=0,c=0,d=0,e=0,f=0,p=0,g=0,
    h=0,i=0,j=0,k=0,l=0,o=0,r=0,u=0, s=0,w=0,x=0,y=0,z=0,L,R;
    LL flag=0, flag1=0, co=0, co1=0, co2=0, co3=0, sum=0;
    LL ma=0,ma1=0, mi=100000000000, mi1=10e9;
    string str, str1, str2,str3,str4;
    LL n,m;
    LL ca = 0;

    cin>>a>>b;
    str = to_string(a);
    str1 = to_string(b);
    string aa = str;
    string bb = str1;
    for(i=0; i<b-1; i++)
    {
        aa = multiplication(aa, str);
    }
    
    for(i=0; i<a-1; i++)
    {
        bb = multiplication(bb, str1);
    }


    string anss = findDiff(aa, bb);
    string final_ans;
    for(i=0, flag = 0; i<anss.size(); i++)
    {
        if(!flag && anss[i]=='0')
            continue;
        else
        {
            flag = 1;
            final_ans += anss[i];
        }
    }
    if(aa.size()>bb.size())
    {
        cout<<final_ans<<endl;
    }
    else if(aa.size()<bb.size())
    {
        cout<<'-'<<final_ans<<endl;
    }
    else
    {
        flag = 0;
        for(i=0; i<aa.size(); i++)
        {
            if((aa[i]-'0')<(bb[i]-'0'))
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<'-'<<final_ans<<endl;
        else
            cout<<final_ans<<endl;
    }




    
    cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    if(((float)clock()/CLOCKS_PER_SEC)>=1.0)
        cerr<<"Need to optimize!!"<<endl;
    else
        cerr<<"RuntimeOKAY!"<<endl;

    return 0;
}