// ******************************* Header Files ***************************//
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ****************************** Macros **************************
#define nline "\n"
#define ff first
#define ss second
#define pb push_back
#define arrs(arr) sizeof(arr)/sizeof(arr[0]);
#define ppb pop_back
#define mp make_pair
#define p push
#define re reverse
#define maxele max_element
#define minele min_element
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define loop(i,n) for(int i = 0; i < n; i++)
#define rloop(i,m,n) for(int i = m; i >= n;i--)
#define er erase
#define mem memset(a,(b),sizeof(a))
#define acc accumulate
#define fbo(x) find_by_order(x)
#define sz(x)   ((int)(x).size())
#define ll long long
#define get(i,m) get<i>(m)
#define oby(x) order_of_key(x)
#define lld long  double
#define ull unsigned long long 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).end(),(x).end()
#define set_bits __builtin_popcountll


//**************************** Constants ***********************************//

 const lld pi = 3.141592653589793238;
 const ll INF = 1e18;
 const ll mod = 1e9 + 7;

// ********************************* Typedef ********************************//

 typedef pair<ll,ll> pll;
 typedef vector<ll> vll;
 typedef vector<string> vst;
 typedef vector<char> vc;
 typedef priority_queue<int> pq;
 typedef priority_queue<ll> pqll;
 typedef priority_queue<int,vector<int>,greater<int>> pqm;
 typedef priority_queue<ll,vector<ll>,greater<ll>> pqmll;
 typedef vector<pair<string,char>> vpsc;
 typedef vector<pair<char,string>> vpcs;
 typedef vector<pll> vpll;
 typedef vector<string> vs;
 typedef deque<int> dq;
 typedef multiset<int> ms;
 typedef multiset<ll> msll;
 typedef multimap<int,int> mp;
 typedef multimap<ll,ll> mpll;
 typedef deque<ll> dqll;
 typedef stack<int> st;
 typedef stack<ll> stll;
 typedef unordered_map<ll,ll> umll;
 typedef map<ll,ll> mll;
 typedef set<ll> sll;
 typedef unordered_set<ll,ll> usll;
 
 // ******************************* Policy Based DS ********************************** //
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// ********************** Some Utility Functions ********************************//
template<typename T>
void _print(T &&t)  { cout << t << "\n"; }
void debugarr(ll arr[], ll n){cerr << "[ "; loop(i,n) cerr << arr[i] << " ";cerr << "]"; cerr << nline;}
template<typename T>
void printvec(vector<T>v){ll n=v.size();loop(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;loop(i,n)s+=v[i];return s;}

// ***************************  Operators Overloading **********************************//
template<typename T1, typename T2> 
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// *************************************** Debugging **************************************** //
template<class T>void print(T x) {cerr << x << " ";}
template<class T, class V> void print(pair<T , V> x)
{print(x.ff); cerr << ':'; print(x.ss);}
template<class T>void print(vector<T> &a) {cerr << '[' << ' ';for(auto x : a){print(x);cerr << ' ';}cerr << ']';}
template<class T>void print(set<T> &a){cerr << '[' << ' ';for(auto x : a){print(x);cerr << ' ';}cerr << ']';}
template<class T>void print(set<T,greater<T>> &a){cerr << '[' << ' ';for(auto x : a){print(x);cerr << ' ';}cerr << ']';}
template<class T>void print(multiset<T> &a){cerr << '[' << ' ';for(auto x : a){print(x);cerr << ' ';}cerr << ']';}
template<class T>void print(multiset<T,greater<T>> &a){cerr << '[' << ' ';for(auto x : a){print(x);cerr << ' ';}cerr << ']';}
template<class T> void print(unordered_set<T> &a){cerr << '[' << ' ';for(auto x : a){ print(x);cerr << ' ';}cerr << ']';}
template<class T, class V>void print(vector<pair<T, V>> &a){cerr << '[' << ' ';for(auto x : a){print(x.ff);cerr << ":";print(x.ss); cerr << ' ';}cerr << ']';}
template <class T, class V>void print(map <T, V> &a){cerr << "[ ";for (auto i : a){print(i);cerr << " "; }cerr << "]";}
template <class T, class V>void print(unordered_map <T, V> &a){cerr << "[ ";for (auto i : a){print(i);cerr << " ";}cerr << "]";}
template <class T>void print(vector<vector<T>> &a){ cerr << "[ ";for (auto i : a){print(i);cerr << " ";}cerr << "]";}
// ********************************** Some Commmonly Used Functions ********************************* //
ll GCD(ll a, ll b){while (b) { a %= b;swap(a, b);} return a;}
ll LCM(ll a,ll b) {return ((ll) a * b) / GCD(a,b);}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;};
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

// ************************************* Online Judge **************************** //
void judge()
{
  #ifndef ONLINE_JUDGE
  freopen("error.txt", "w", stderr);
  #endif
 
  #ifndef ONLINE_JUDGE
  #define debug(x)  cerr << #x << " = ";  print(x);  cerr << nline;
  #define debug2(x,y) cerr << #x << " = "; print(x); cerr << #y << " = "; print(y); cerr << nline; 
  #else
  #define debug(x) 
  #define debug2(x,y)
  #endif
}

 // ******************************** Main Solve Function ******************************* //

void Mayank() 
{
 ll arr[10];
 vector<ll> v(10);

 // 1> Fill()
 fill(v.begin(),v.end(),4);
 fill(arr,arr + 10,4);

 for(auto x : v)
 {
  cout << x << " ";
 }

 // 2> isLower(),isUpper()

  char x = 'a';
  char y = 'A';
  cout << (islower(x) ? "YES" : "NO") << nline;
  cout << (isupper(y) ? "YES" : "NO") << nline;

// 3> toupper, tolower
 string str = "MayAnK";
 ll n = sz(str);
 for(int i = 0; i < n; i++)
 {
  if(islower(str[i]))
  {
    str[i] = toupper(str[i]);
  }
  else{
    str[i] = tolower(str[i]);
  }
 }

 //  4> bits functions

 ll n;
 cin >> n;

 cout << decToBinary(n) << nline;
 cout << "SetBits = " << __builtin_popcountll(n) << nline;
 cout << "parity = " << (__builtin_parity(x) ? "YES" : "NO") << nline;
 cout << "clz =" << __builtin_clz(n) << nlinel
 cout << "ctz" << __builtin_ctz(n) << nline;  


 // 5> is_sorted
 
 vector<ll> sorted {1,5,8,9,10,15,20,22};
 vector<ll> unsorted {5,1,10,8,11,9,10,20};

 cout << (is_sorted(all(sorted)) ? "YES" : "NO") << nline;
 cout << (is_sorted(all(unsorted)) ? "YES" : "NO") << nline;


// 6> is_permutation
 ll a[] = {1,7,0,2};
 ll n = arrs(a);
 ll b[] = {0,7,2,1};
 if(is_permutation(a,a + n,b))
 {
  cout << "YES" << nline;
 }
 else{
  cout << "YES" << nline;
 }

 ll a2[] = {1,7,0,2};
 ll n = arrs(a);
 ll b2[] = {4,7,2,1};
 if(is_permutation(a2,a2 + n,b2))
 {
  cout << "YES" << nline;
 }
 else{
  cout << "YES" << nline;
 }

 // Some Basic Functions
 // pow(x,y);
 cout << pow(2,2) << nline;
 cout << pow(3,3) << nline;
// sqrt(x)
 cout << sqrt(24) << nline;
 // __gcd()
 cout << __gcd(10,4) << nline;
 // floor()
 cout << floor(5.6) << nline;
 // Ceil
 cout << ceil(5.6) << nline;
 // setprecision()
 cout << sqrt(24) << nline;
 cout << setprecision(10) << sqrt(24) << nline;


}

// *********************************  Main Function **************************************//
int main()
{
    judge();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   

    int te;
    cin >> te;
    while(te--)
    {
    Mayank();
    }

  return 0;
}
