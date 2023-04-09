#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pat, int* lps) 
{ 
    int j = 0; 
  
    lps[0] = 0; // lps[0] is always 0 

    int i = 1; 
    while (i < pat.size()) { 
        if (pat[i] == pat[j]) { 
            j++; 
            lps[i] = j; 
            i++; 
        } 
        else
        { 
            if (j != 0) { 
                j = lps[j - 1]; 
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}

bool IsKPeriodic(const string& txt, int k){
	if(k <= 0) return false;
	if(txt.size() % k != 0) return false;
	
	int right = txt.size() / k;
	string pat = "";
	for(int i = 0;i < k;i++){
		pat = pat + txt[i];
	}
	
	int count = 0;
	int * lps = new int[pat.size()];

    computeLPS(pat, lps); 
  
    int i = 0;  
    int j = 0; 
    while (i < txt.size()) { 
        if (pat[j] == txt[i])
        { 
            j++; 
            i++; 
        } 
        if (j == pat.size()) { 
            count += 1;
            j = lps[j - 1]; 
        } 
        else if (i < txt.size() && pat[j] != txt[i]) { 
            if (j != 0)
            {
                j = lps[j - 1]; 
            }
            else
            {
                i = i + 1;
            }
        } 
    }
	
	if(count == right) return true;
	return false; 
}

int main()
{
	cout << IsKPeriodic("ABCABCABC", 3);
    return 0;
}