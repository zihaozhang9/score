#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int n[100]; //���� ��N��ѧ�� 
	int id[100]; //ѧ��ѧ��
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
	printf("����ѧ��ѧ��\n");
		scanf("%d",&stu.id[m]);
	printf("����ѧ������\n");
	    scanf("%s",&stu.name[m]);
	printf("����ѧ�������ɼ�\n");
	    scanf("%d",&stu.gaoshu[m]);
	printf("����ѧ������ɼ�\n");
 	    scanf("%d",&stu.dawu[m]);
	printf("����ѧ��Ӣ��ɼ�\n");
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
			printf("ѧ��ѧ��%d\n",stu.id[i]);
	        printf("ѧ������%s\n",stu.name[i]);
			printf("ѧ�������ɼ�%d\n",stu.gaoshu[i]);
			printf("ѧ������ɼ�%d\n",stu.dawu[i]);
			printf("ѧ��Ӣ��ɼ�%d\n\n",stu.yingyu[i]);
		}
	
	fclose(fp);

}

void xiugai(int ci,int m)
{
	printf("����ѧ��ѧ��\n");
		scanf("%d",&stu.id[ci]);
	printf("����ѧ������\n");
	    scanf("%s",&stu.name[ci]);
	printf("����ѧ�������ɼ�\n");
	    scanf("%d",&stu.gaoshu[ci]);
	printf("����ѧ������ɼ�\n");
 	    scanf("%d",&stu.dawu[ci]);
	printf("����ѧ��Ӣ��ɼ�\n");
	    scanf("%d",&stu.yingyu[ci]);
		fp=fopen("student.txt","r+");
		fseek(fp,0,0);
		for(i=0;i<m;i++)
		{
			fprintf(fp,"%4d%20d%20s%4d%4d%4d\n",stu.n[i],stu.id[i],stu.name[i],stu.gaoshu[i],stu.dawu[i],stu.yingyu[i]);
		}
		fclose(fp);
}

void shanchu(int ci,int m)//ɾ������
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
		printf("ѭ������");


	}
		fp=fopen("student.txt","r+");
		fseek(fp,0,0);
		for(i=0;i<m;i++)
		{

			if(i==m)
			{
				printf("i====m��һ����\n");
				fprintf(fp,"%4s%20s%20s%4s%4s%4s\n"," "," "," "," "," "," ");

			}
			else
			{
				printf("��û����û�У�\n");
	
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
	   printf("�޷��ҵ��ļ�\n");
	   exit(0);
   }
  
  
	   printf("������Ҫ����ѧ������������ĸ\n");
       scanf("%s",&ma);
	   	for(i=0;i<m;i++)
		{
			fscanf(fp,"%4d%20d%20s%4d%4d%4d\n",&stu.n[i],&stu.id[i],&stu.name[i],&stu.gaoshu[i],&stu.dawu[i],&stu.yingyu[i]);
			na=stu.name[0][i];
			if(ma==na)
		 {
		   printf("���ҵ�����ѧ����ϢΪ��\n");
				   printf("����  ѧ��  �����ɼ�  ����ɼ�  Ӣ��ɼ�  \n");
		printf("%s%10d%4d%4d%4d\n",stu.name[i],stu.id[i],stu.gaoshu[i],stu.dawu[i],stu.yingyu[i]);

		 		   h=1;
		   break;
		 }
		}
	

      if(h==0)
	  {
	   printf("��ѧ����Ϣ������\n");
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
printf("������߳ɼ�%d\n",l);
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
printf("��ѧ������߳ɼ�%d\n",l);
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
printf("��ѧӢ����߳ɼ�%d\n",l);
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
printf("�������������%d\n",l);
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
printf("��ѧ�����������%d\n",l);
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
printf("Ӣ�ﲻ�������%d\n",l);
}



main()
{
	
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1 ������ҵ��ѧ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1   ��������   \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1 ѧ������ϵͳ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1  ���ֹ�����  \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1   ������ͬ   \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1   ���Գ�Ϯ   \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�����ˣ�\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t����껣�����\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t13521116��13521334\n");


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
		
		
			fseek(fp,0,2); //�α��ƶ����ļ���β 2�ǽ�β����˼
			if(ftell(fp)==0)
			{
			printf("����%d������\n",m);
			}
			else
			{
			printf("����%d������\n",m+1);
			}
			fclose(fp);
	while(1)
	{
		
		   
		    printf("\t����������������������ӭ����ѧ������ϵͳ��������������������");
        printf("\t\t\t��     ���ѧ����Ϣ     �밴1                             ��");
        printf("\t\t\t��     ����ѧ����Ϣ     �밴2                             ��");
        printf("\t\t\t��     ��ѯѧ����Ϣ     �밴3                             ��");
        printf("\t\t\t��     ɾ��ѧ����Ϣ     �밴4                             ��");
        printf("\t\t\t��     ��Ϣȱʡ��ѯ     �밴5                             ��");
        printf("\t\t\t��     �ɼ�ͳ�Ʋ�ѯ     �밴6                             ��");
        printf("\t\t\t������������������������������������������������������������\n");
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
			printf("�����%d��ѧ����Ϣ\n",m+1);
			    xieru(m);
			  
			    n++;
			}
			else
			{
				printf("�����%d��ѧ����Ϣ\n",m+2);
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


			printf("���ĵڼ���ѧ���ɼ�?");
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
printf("ɾ���ڼ������ݣ�");
		scanf("%d",&ci);
				shanchu(ci-1,m);
			
		/*	if(n==0)//ok
			{
				printf("nnnnn====000ɾ���ڼ������ݣ�");
				scanf("%d",&ci);
				shanchu(ci-1,m);
			}
			else
			{
				printf("nnnnn eeeeeeɾ���ڼ�������?");
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
			printf("�������������1~6");
					
		}//switch�Ľ��� 
	
	}//while�Ľ���
}//main�Ľ���