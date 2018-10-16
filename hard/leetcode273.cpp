class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        return int_to_string(num).substr(1);
    }
    string int_to_string(int n){
        if(n >= 1000000000) return int_to_string(n/1000000000) + " Billion" + int_to_string(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000)    return int_to_string(n/1000000) + " Million" + int_to_string(n - 1000000 * (n / 1000000));
        else if(n >= 1000)   return int_to_string(n/1000) + " Thousand" + int_to_string(n - 1000 * (n / 1000));
        else if(n >= 100)    return int_to_string(n/100) + " Hundred" + int_to_string(n - 100 * (n / 100));
        else if(n >= 20)     return string(" ") +  num2[n/10 - 2] + int_to_string(n - 10 * (n / 10));
        else if(n >= 1)  return string(" ") + num1[n-1];
        else return   "";
    }
    vector<string> num1 = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> num2 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};
