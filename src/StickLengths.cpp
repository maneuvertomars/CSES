#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FTL ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
#define all(x) x.begin(), x.end()
#define endl "\n";
#define ff first
#define ss second
#define ll long long
 
void see(multiset<int> &h){
    for(auto &it:h) cout<<it<<' ';cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i: v){
        cin>>i;
    }
    sort(all(v));
    vector<ll> left(n);
    left[0] = 0;
    ll pref = v[0];
    for(int i=1;i<n;i++){
        left[i] = 1ll*i*v[i] - pref;
        pref += v[i];
    }
    ll ans = 1e15;
    ll suf = 0;
    int cnt = 0;
    for(int i = n-1;i>=0;i--){
        ans = min(ans, max(0ll,suf - 1ll*cnt*v[i]) + left[i]);
        cnt++;
        suf += v[i];
    }
    cout<<ans;
}
 
 
int main() {
    FTL
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}