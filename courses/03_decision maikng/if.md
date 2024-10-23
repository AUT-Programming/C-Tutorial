# دستور if در C

]
ساختار دستور if در برنامه نویسی C به شکل زیر است:

	if(عبارت شرطی){
		/*اگر عبارت شرطی درست باشد دستوراتی که در
		 بدنه نوشته شده باشند اجرا می شوند
		*/
	}

+ اگر عبارت شرطی درست (true) باشد، دستورات داخل بدنه if اجرا می شوند.
+ اگر عبارت شرطی نادرست (false) باشد، دستورات داخل بدنه if اجرا نمی 
	شوند و کنترل برنامه به بعد از دستور if (بعد از }) منتقل خواهد شد.
	
مثال :

    #include <stdio.h>
    
    int main()
    {
        if (20 > 18) {
         printf("20 is greater than 18");
        } 
        return 0;
    }
output = 20 is greater than 18
   

اگر این قطعه کد رو داشته باشیم و توی IDE ران کنیم میبینیم عبارت "x is greater than 
  y"چاپ میشه . این یعنی که عبارت شرطی جلوی if درست بوده !

حالا اگه عبارت شرطی اشتباه باشه چی میشه ؟
آفرین ! هر چیزی که توی بدنه if نوشته شده توسط کامپایلر نادیده گرفته میشه و اجرا نمیشه .
برای نمونه توی مثال قبلی اگه توی عبارت شرطی داشتیم (18 > 20) چون ۱۸ از ۲۰ بزرگتر نیست پس عبارت شرطی اشتباهه و خطوط داخلی if اجرا نمی شن و دستور print هم نمی تونه چیزی توی ترمینال چاپ کنه .... 

مثال :


    #include <stdio.h>
    int main()
    {
        if (20 < 18) {
         printf("20 is greater than 18");
        } 
        return 0;
    }
output : نداریم

راستی توی عبارت شرطی از متغیر ها هم میتونیم استفاده کنیم و از هر نمادی که مفهوم مقایسه رو بتونه منتقل کنه مجازیم که استفاه کنیم .

    #include <stdio.h>
    int main()
    {
        int x = 20;
        int y = 18;
        if (x > y) {
            printf("x is greater than y");
        } 
        return 0;
    }
output : x is greater than y
# عملگر ها
همونطوری که از مباحث قبلی یاد گرفتید میتونیم بین متغیر ها از عملگر های مختلفی استفاده کنیم .
+ < کوچکتر از
+ <= کوچکتر یا مساوی
+ >  بزرگتر از
+ >= بزرگتر یا مساوی با
+ == مساوی با
+ != مخالف با
+ || یا(or)
+ && و (and)
+ ! نقیض (not)

> دقت کنید که عملگر تساوی(==) متفاوت از عملگر مقداردهی(=) هست ، این مسئله یکی از متداول ترین اشتباهاته نو برنامه نویس هاست !!!

مثال :


    #include <stdio.h>
    
    int main(){
    
       int a = 5;
       int b = 20;
    
       if (a && b){
          printf("Line 1 - Condition is true\n" );
       }
    
       if (a || b){
          printf("Line 2 - Condition is true\n" );
       }
    
       /* lets change the value of  a and b */
       a = 0;
       b = 10;
    
       if (a && b){
          printf("Line 3 - Condition is true\n" );
       } else {
          printf("Line 3 - Condition is not true\n" );
       }
    
       if (!(a && b)){
          printf("Line 4 - Condition is true\n" );
       }
    
       return 0;	
    }
output :

Line 1 - Condition is true

Line 2 - Condition is true

Line 3 - Condition is not true

Line 4 - Condition is true


# دستور If-Else
تو این قسمت کلا دو حالت داریم :
یا عبارت شرطی درسته که بدنه if اجرا میشه یا عبارت شرطی غلطه که در اینصورت بدنه else اجرا میشه . بریم یه مثال ببینیم که بهتر متوجه بشید .
مثال :

    #include <stdio.h>
    
    int main()
    {
        int x = 20;
        int y = 18;
        if (x > y) {
            printf("x is greater than y");
        } 
        else {
            printf("x is not greater than y");
    
        }
        return 0;
    }
output : x is greater than y

چون عبارت شرطی درست بود فقط بدنه if و دستوراتی که توی بلاک if قرار دارن اجرا میشن .
حالا اگه عبارت شرطی غلط بود جریان چی میشه؟
آفرین ! 
اینبار فقط بلاک else اجرا میشه . بریم یه مثال دیگه ببینیم :
مثال :

    #include <stdio.h>
    
    int main()
    {
        int x = 20;
        int y = 18;
        if (x < y) {
            printf("x is greater than y");
        } 
        else {
            printf("x is not greater than y");
    
        }
        return 0;
    }
output: x is not greater than y

مثال :

    #include <stdio.h>
    
    int main(){
    
       int phy = 50;
       int maths = 60;
    
       if (phy < 50 || maths < 50){
          printf("Result:Fail");
       }
       else {
          printf("Result:Pass");
       }
    
       return 0;
    }
output: Result:Pass

#دستور else-if

    if (عبارت شرطی ۱) {
    
        // دستور(ها)
    
    }
    
    else if(عبارت شرطی ۲) {
    
        // دستور(ها)
    
    }
    
    else if (عبارت شرطی ۳) {
    
        // دستور(ها)
    
    }
    
        .
    
        .
    
    else {
    
        // دستور(ها)
    
    }


دستور else if این امکان را فراهم می کند که بین چندین عبارت شرطی بررسی رو انجام بدیم و دستورات متفاوت رو اجرا کنیم .


مثال : 

    	#include <stdio.h>
    
    int main(void) {
       int age = 15;
    
       if (age < 18) {
          printf("You need to be over 18 years old to continue\n");
       }else if (age < 21) {
          printf("You need to be over 21\n");
       } else {
          printf("You are over 18 and older than 21 so you can continue \n");
       }
    }
output = You need to be over 18 years old to continue

در این مثال اولین عبارت شرطی درست بود پس فقط دستورات درون بلاک اولین شرط اجرا می شوند و کامپایلر بقیه شرط ها و بلاک ها را نادیده می گیرد .

مثال :

    #include <stdio.h>
    
    int main()
    {
    	int n = 0;
    
    
    	if (n > 0) {
    		printf("Positive");
    	}
    
    
    	else if (n < 0) {
    		printf("Negative");
    	}
    
    	else {
    		printf("Zero");
    	}
    	return 0;
    }
output : Zero

در این مثال هم چون n = 0 هست و صفر نه مثبته نه منفی پس شرط های قبلش اجرا نمیشن .

مثال :

    #include <stdio.h>
    int main()
    {
        int marks = 71;
        if (marks <= 100 && marks >= 90)
            printf("A+ Grade");
        else if (marks < 90 && marks >= 80)
            printf("A Grade");
        else if (marks < 80 && marks >= 70)
            printf("B Grade");
        else if (marks < 70 && marks >= 60)
            printf("C Grade");
        else if (marks < 60 && marks >= 50)
            printf("D Grade");
        else
            printf("F Failed");
        return 0;
    }
output : ‌‌‌B Grade

