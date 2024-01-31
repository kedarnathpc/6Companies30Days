class Solution {
    bool flag=false;
public:
    string one(int num){
        if(num==0)
            return "";
        string numbers[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string curr = "";
        if(flag)
            curr+=" ";
        flag=true;
        curr+=numbers[num];
        return curr;
    }
    string ten(int num){
        if(num<20)
            return one(num);
        int val = num/10;
        num = num%10;
        string number[10]={"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(flag)
            return " "+number[val] + one(num);
        flag=true;
        return number[val] + one(num);
    }
    string hundred(int num){
        if(num<100)
            return ten(num);
        int hun = num/100;
        num=num%100;
        return one(hun)+" Hundred"+ ten(num);
        
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string ans = "";
        int billion = num/1000000000;
        num = num%1000000000;
        int million = num/1000000;
        num = num%1000000;
        int thousand = num/1000;
        num = num%1000;
        // cout<<billion<<" "<<million<<" "<<thousand<<" "<<num<<endl;
        if(billion){
            ans += hundred(billion)+" Billion";
        }
        if(million){
            ans += hundred(million)+" Million";
        }
        if(thousand){
            ans += hundred(thousand)+" Thousand";
        }
        ans+=hundred(num);
        return ans;
    }
};