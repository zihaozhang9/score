#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int n[100]; //排序 第N个学生 
	int id[100]; //学生学号
	char name[20][100];
	int gaoshu[100];
	int dawu[100];
	int yingyu[100];

}stu;
int i=0;
int j=0;
int m=0;
int n=0;
int d=0;
  int temp;
  int l;
FILE *fp;
void xieru(int m)
{
	fp=fopen("student.txt","r+");
	stu.n[m]=m;
	printf("输入学生学号\n");
		scanf("%d",&stu.id[m]);
	printf("输入学生名字\n");
	    scanf("%s",&stu.name[m]);
	printf("输入学生高数成绩\n");
	    scanf("%d",&stu.gaoshu[m]);
	printf("输入学生大物成绩\n");
 	    scanf("%d",&stu.dawu[m]);
	printf("输入学生英语成绩\n");
	    scanf("%d",&stu.yingyu[m]);
		fseek(fp,0,2);
		fprintf(fp,"%4d%20d%20s%4d%4d%4d\n",stu.n[m],stu.id[m],stu.name[m],stu.gaoshu[m],stu.dawu[m],stu.yingyu[m]);
		fclose(fp);
}

void dayin(int m)
{
	
	fp=fopen("student.txt","r+");
		for(i=0;i<m;i++)
		{
			fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
			printf("学生学号%d\n",stu.id[i]);
	        printf("学生姓名%s\n",stu.name[i]);
			printf("学生高数成绩%d\n",stu.gaoshu[i]);
			printf("学生大物成绩%d\n",stu.dawu[i]);
			printf("学生英语成绩%d\n\n",stu.yingyu[i]);
		}
	
	fclose(fp);

}

void xiugai(int ci,int m)
{
	printf("输入学生学号\n");
		scanf("%d",&stu.id[ci]);
	printf("输入学生名字\n");
	    scanf("%s",&stu.name[ci]);
	printf("输入学生高数成绩\n");
	    scanf("%d",&stu.gaoshu[ci]);
	printf("输入学生大物成绩\n");
 	    scanf("%d",&stu.dawu[ci]);
	printf("输入学生英语成绩\n");
	    scanf("%d",&stu.yingyu[ci]);
		fp=fopen("student.txt","r+");
		fseek(fp,0,0);
		for(i=0;i<m;i++)
		{
			fprintf(fp,"%4d%20d%20s%4d%4d%4d\n",stu.n[i],stu.id[i],stu.name[i],stu.gaoshu[i],stu.dawu[i],stu.yingyu[i]);
		}
		fclose(fp);
}

void shanchu(int ci,int m)//删除函数
{
	printf("shangchu  m=%d\n",m);

	for(i=ci;i<m;i++)
	{
        printf("cccccccccc========%d\n",ci);

		stu.id[ci]=stu.id[ci+1];

		strcpy(stu.name[ci],stu.name[ci+1]);
	
		stu.gaoshu[ci]=stu.gaoshu[ci+1];

		stu.dawu[ci]=stu.dawu[ci+1];

		stu.yingyu[ci]=stu.yingyu[ci+1];
		printf("循环了吗");


	}
		fp=fopen("student.txt","r+");
		fseek(fp,0,0);
		for(i=0;i<m;i++)
		{

			if(i==m)
			{
				printf("i====m吗一定是\n");
				fprintf(fp,"%4s%20s%20s%4s%4s%4s\n"," "," "," "," "," "," ");

			}
			else
			{
				printf("有没有有没有？\n");
	
			fprintf(fp,"%4d%20d%20s%4d%4d%4d\n",stu.n[i],stu.id[i],stu.name[i],stu.gaoshu[i],stu.dawu[i],stu.yingyu[i]);
				
			}

		}
		fclose(fp);

}

void que(int m)
{
	int h=0;
   char na;
   char ma;
  
   fp=fopen("student.txt","r+");
  if(fp==NULL)
   {
	   printf("无法找到文件\n");
	   exit(0);
   }
  
  
	   printf("请输入要查找学生姓名的首字母\n");
       scanf("%s",&ma);
	   	for(i=0;i<m;i++)
		{
			fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
			na=stu.name[0][i];
			if(ma==na)
		 {
		   printf("已找到，该学生信息为：\n");
				   printf("姓名  学号  高数成绩  大物成绩  英语成绩  \n");
		printf("%s%10d%4d%4d%4d\n",stu.name[i],stu.id[i],stu.gaoshu[i],stu.dawu[i],stu.yingyu[i]);

		 		   h=1;
		   break;
		 }
		}
	

      if(h==0)
	  {
	   printf("该学生信息不存在\n");
	  }
       fclose(fp);
      
}

void gaoshumax(int m)
{
	fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	fclose(fp);
l=0;
for(i=0;i<m;i++)
{
	if(stu.gaoshu[i]>l)
	{
		l=stu.gaoshu[i];
	}
}
printf("高数最高成绩%d\n",l);
}

void dawumax(int m)
{
	fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	fclose(fp);
l=0;
for(i=0;i<m;i++)
{
	if(stu.dawu[i]>l)
	{
		l=stu.dawu[i];
	}
}
printf("大学物理最高成绩%d\n",l);
}

void yingyumax(int m)
{
	fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	fclose(fp);
l=0;
for(i=0;i<m;i++)
{
	if(stu.yingyu[i]>l)
	{
		l=stu.yingyu[i];
	}
}
printf("大学英语最高成绩%d\n",l);
}

void gaoshulose(int m)
{
	l=0;
	fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	fclose(fp);
for(i=0;i<m;i++)
{
	if(stu.gaoshu[i]<60)
	{
		l++;
	}
}
printf("高数不及格个数%d\n",l);
}

void dawulose(int m)
{
	l=0;
	fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	fclose(fp);
for(i=0;i<m;i++)
{
	if(stu.dawu[i]<60)
	{
		l++;
	}
}
printf("大学物理不及格个数%d\n",l);
}

void yingyulose(int m)
{
	l=0;
	fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	fclose(fp);
for(i=0;i<m;i++)
{
	if(stu.yingyu[i]<60)
	{
		l++;
	}
}
printf("英语不及格个数%d\n",l);
}



main()
{
	
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1 北京工业大学 \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1   电信三班   \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1 学生管理系统 \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1  纯手工制作  \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1   如有雷同   \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1   绝对抄袭   \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t制作人：\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t张子昊，张哲\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t13521116，13521334\n");


	struct student stu;
	int step,ci;

		fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	
	for(i=0;i<99;i++)
	{
		if(stu.n[i+1]>stu.n[i])
		{
			m=stu.n[i+1];

		}
	}
		
		
			fseek(fp,0,2); //游标移动到文件结尾 2是结尾的意思
			if(ftell(fp)==0)
			{
			printf("共有%d个数据\n",m);
			}
			else
			{
			printf("共有%d个数据\n",m+1);
			}
			fclose(fp);
	while(1)
	{
		
		   
		    printf("\t┏━━━━━━━━━欢迎进入学生管理系统━━━━━━━━━┓");
        printf("\t\t\t┃     添加学生信息     请按1                             ┃");
        printf("\t\t\t┃     更改学生信息     请按2                             ┃");
        printf("\t\t\t┃     查询学生信息     请按3                             ┃");
        printf("\t\t\t┃     删除学生信息     请按4                             ┃");
        printf("\t\t\t┃     信息缺省查询     请按5                             ┃");
        printf("\t\t\t┃     成绩统计查询     请按6                             ┃");
        printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		scanf("%d",&step);
		switch(step)
		{
		case 1:
	
fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	
	for(i=0;i<99;i++)
	{
		if(stu.n[i+1]>stu.n[i])
		{
			m=stu.n[i+1];

		}
	}
		
			fseek(fp,0,2);

			fclose(fp);


				fp=fopen("student.txt","r+");
				fseek(fp,0,2);
			if(ftell(fp)==0)
			{
			printf("输入第%d个学生信息\n",m+1);
			    xieru(m);
			  
			    n++;
			}
			else
			{
				printf("输入第%d个学生信息\n",m+2);
			    xieru(m+1);
			    m++;
		     	n++;
				printf("%d\n",m);
			}
			fclose(fp);
			break;
		case 2:
			fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	
	for(i=0;i<99;i++)
	{
		if(stu.n[i+1]>stu.n[i])
		{
			m=stu.n[i+1];

		}
	}


			printf("更改第几个学生成绩?");
			scanf("%d",&ci);
			xiugai(ci-1,m+1);
			break;
		case 3:

			if(n==0)
			{
	
				dayin(m+1-d);
			}
			else
			{
	
				dayin(m+1-d);
			}
	
			break;
		case 4:

					fp=fopen("student.txt","r+");
	for(i=0;i<100;i++)
	{
		fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
	
	}
	
	for(i=0;i<99;i++)
	{
		if(stu.n[i+1]>stu.n[i])
		{
			m=stu.n[i+1];

		}
	}
		printf("shangchu  m=%d\n",m);
printf("删除第几个数据？");
		scanf("%d",&ci);
				shanchu(ci-1,m);
			
		/*	if(n==0)//ok
			{
				printf("nnnnn====000删除第几个数据？");
				scanf("%d",&ci);
				shanchu(ci-1,m);
			}
			else
			{
				printf("nnnnn eeeeee删除第几个数据?");
				scanf("%d",&ci);
				shanchu(ci-1,m);
			}*/
			d++;
			break;
		case 5:
			if(n==0)
			{
				que(m+1-d);
			}
			else
				que(m-d);
	
			break;
		case 6:
				
			gaoshumax(m+1);
			dawumax(m+1);
			yingyumax(m+1);
			gaoshulose(m+1);
			dawulose(m+1);
			yingyulose(m+1);
			break;
		default:
			printf("输入错误请输入1~6");
					
		}//switch的结束 
	
	}//while的结束
}//main的结束