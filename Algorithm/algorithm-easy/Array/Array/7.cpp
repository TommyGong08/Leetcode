class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int flag=0;
        //对最后一位数
        if(len>2){
            if(digits[len-1]+1==10) {
            digits[len-1]=0;
            flag=1;
        }else{
            digits[len-1]++;
            flag=0;
        }
        for(int j=len-2;j>0;j--){
            if(flag==0){//不进位
                continue;
            }
            else if(flag==1){
                if((digits[j]+1)==10){
                    digits[j]=0;
                    flag=1;
                }
                else{
                    digits[j]++;
                    flag=0;
                }
            }
        }
        if(flag==0){
        }
        else if(flag==1){
            if(digits[0]==9){
                digits.push_back(digits[len-1]);
                for(int j=len-1;j>1;j--){
                    digits[j]=digits[j-1];
                }
                digits[1]=0;
                digits[0]=1;
            }
            else {
                digits[0]++;
            }
        }
    }
    else if(len==1){
          if(digits[0]==9){
              digits[0]=1;
              digits.push_back(0);
          }
          else digits[0]++;
      }  
      else if(len==2){
          int flag=0;
          if(digits[1]==9){
              flag=1;
              digits[1]=0;
          }
          else {
              digits[1]++;
              flag=0;
          }
          if(flag==0){
          }
          else if(flag==1){
              if(digits[0]<9){
                  digits[0]++;
              }
              else if(digits[0]==9){
                  digits.push_back(digits[1]);
                  digits[1]=0;
                  digits[0]=1;
              }
          }
      }
      return digits;
    }
};