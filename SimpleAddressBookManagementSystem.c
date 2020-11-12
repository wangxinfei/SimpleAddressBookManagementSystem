#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#define SELF_PWD_LEN 25
#define SELF_ARRAY_LEN 10 
#define CONTACT_ARRAY_LEN 100
#define CONTACT_NO_LEN 100
#define CONTACT_NAME_LEN 100
#define CONTACT_SEX_LEN 100
#define CONTACT_TEL_LEN 100
#define CONTACT_ADD_LEN 100

typedef struct _self
{
	char pwd[SELF_PWD_LEN];
}Self;

Self g_self[SELF_ARRAY_LEN] = {"******"};
int g_self_count = 1;

typedef struct _contact
{
	char no[CONTACT_NO_LEN];
	char name[CONTACT_NAME_LEN];
	char sex[CONTACT_SEX_LEN];
	char tel[CONTACT_TEL_LEN];
	char add[CONTACT_ADD_LEN];
}Contact;

Contact g_contacts[CONTACT_ARRAY_LEN] = 
		{{"01", "小花", "女", "12345678910", "曲阜师范大学"},
		{"02", "小葡萄", "女","10987654321", "曲阜师范大学"},
		{"03","小柚子","男","18561526859","曲阜师范大学"}, 
		{"04","小蘑菇","男","88886666222","曲阜师范大学"},
		{"05","花棉袄","女","15806290348","曲阜师范大学"}}; 
int g_contacts_count = 5;

void init();
int chooseNumber();
int Login();
void Manage();
void addContact();
void deleteContact();
void quiryContact();
void changeContact();
void listContact();
void quit();
int main()
{
   init();
}
void init()
{
	int a;
	a=chooseNumber();
	
	if(a==1)
	{
		if(Login()==1)
		{
		system("cls");
		Manage();	
		}
		else
		{
			printf("登陆失败\n");
		}
	}
}
int chooseNumber()
{
	system("color 3D");
	int a;
	printf("\t\t*******************************************\n");
	printf("\t\tの                                       の\n");
	printf("\t\t の                通讯录               の \n");
	printf("\t\t  の                                   の  \n");
	printf("\t\t   ************************************\n");
	printf("\t\t   按1进入开锁界面......\n");
	scanf("%d",&a);
	return a;
	
}
int Login()
{
	system("cls");
	system("color 8C");
	HeadShow();
	int i;
	int j=0;
	char pwd[SELF_PWD_LEN];
	for(j;j<3;j++)
	{
    	printf("\t\t请输入解锁密码：");
    	scanf("%s",pwd);
    	for(i=0;i<g_self_count;i++)
    	{
	    	if(strcmp(pwd, g_self[i].pwd)==0)
	    	{
			    return 1;
			}	   
		}
	    printf("密码错误\n"); 
    }
    return 0;
}
void HeadShow()
{
    
    printf("      #################         通讯录管理系统          #################\n");  
    printf("      -------------------------------------------------------------------\n");  
}   
void Manage()
{
	char option;
	while(1)
	{
	    system("cls");
	    system("color 4E");
	    printf("\t\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n" );
	    printf("\t\t※                通 讯 录 管 理 系 统                ※\n" );
		printf("\t\t※                                                    ※\n" );
		printf("\t\t※    1. 添加联系人信息          4. 修改联系人信息    ※\n" );
	    printf("\t\t※    2. 删除联系人信息          5. 浏览联系人信息    ※\n" );
	    printf("\t\t※    3. 查询联系人信息          6. 退出通讯录        ※\n" );
	    printf("\t\t※                                                    ※\n" );
	    printf("\t\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n" );
    	printf("请选择：");
    	scanf("%c",&option);
    	fflush(stdin);

    	switch(option)
    	{
    		case '1':
                addContact();
	        	break;
	    	case '2':
	        	deleteContact();
	        	break;
	      	case '3':
	        	quiryContact();
	    	    break;
	    	case '4':
	    	    changeContact();
	        	break;
	    	case '5':
	        	listContact();
	        	break;
	    	case '6':
	        	quit();
	        	break;
    	}
	}
}

void addContact()
{
	system("cls");
	system("color 0F");
	HeadShow();
	Contact contact;
	int i,n=-1;
	printf("\t\t    ------------创建联系人信息-------------\n");
	printf("\t\t请输入ID：");
	scanf("%s",contact.no);
	for(i=0;i<g_contacts_count;i++)
	{
		if(!strcmp(contact.no,g_contacts[i].no))
		{
			n=i;
			printf("\t\t该联系人已存在！"); 
			break;
		}
	}
	if(n==-1)
		{
			printf("\t\t请输入姓名：");
			scanf("%s",contact.name);
			printf("\t\t请输入性别：");
			scanf("%s",contact.sex);
			printf("\t\t请输入电话号码：");
			scanf("%s",contact.tel);
			printf("\t\t请输入家庭住址：");
			scanf("%s",contact.add);
			g_contacts[g_contacts_count]=contact;
			g_contacts_count++;
			
			printf("创建成功\n");
		}
	system("pause");
}
void deleteContact()             //删除联系人信息 
{
	system("cls");
	system("color 6D");
	HeadShow();
    char number[CONTACT_NO_LEN];
	int i;
	int index=-1;

	printf("\t\t********************删除联系人信息********************\n");
	printf("\t\t请输入要删除的联系人ID：");
	scanf("%s", number);
	for(i = 0; i < g_contacts_count; i++)
	{
		if(!strcmp(number, g_contacts[i].no))
		{
			index=i;
			break;
		}	
	}
	if(index==-1)
		printf("该联系人不存在");
	else
	{
		for(i=index;i<g_contacts_count-1;i++)
		{
			g_contacts[i]=g_contacts[i+1];
		}
		g_contacts_count--;
		printf("删除成功！\n");
		
	}
	system("pause");	
}
void quiryContact()
{
	system("cls");
	system("color 1F");
	HeadShow();
	char number[CONTACT_NO_LEN];
	int i;
	printf("\t\t********************查询联系人信息********************\n");
	printf("\t\t请输入要查询的联系人ID：");
	scanf("%s",number);
	for(i = 0; i < g_contacts_count; i++)
	{
		if(strcmp(number, g_contacts[i].no)==0)
		{
			system("cls"); 
			printf("\t\tID\t姓名\t性别\t手机号码\t家庭住址\n");
			printf("\t\t%s\t%s\t%s\t%s\t%s\n",
			       g_contacts[i].no, g_contacts[i].name, g_contacts[i].sex,
				    g_contacts[i].tel,g_contacts[i].add);
					break;
		}	 
	}
	if(i==g_contacts_count)
		{
			printf("该联系人不存在");
		}
	system("pause");
}
void changeContact()                 //修改联系人信息 
{
	char temp[CONTACT_NO_LEN];
	int i;
	int index=-1;
	
	system("cls");
	system("color 18");
	printf("\t\t*******************修改联系人信息********************\n");
	printf("\t\t请输入要修改的联系人ID：");
	scanf("%s",temp);
	for(i=0;i<g_contacts_count;i++)
	{
		if(strcmp(temp,g_contacts[i].no)==0)
		{
			index=i;
			break;
		}
	}
	if(index==-1)
	printf("账户不存在！\n");
	else
	{
		printf("\t\t请输入新的账户信息：");
		printf("请输入ID："); 
		scanf("%s",g_contacts[index].no);
		printf("\t\t请输入姓名：");
		scanf("%s",g_contacts[index].name);
		printf("\t\t请输入性别：");
		scanf("%s",g_contacts[index].sex);
		printf("\t\t请输入电话号码：");
		scanf("%s",g_contacts[index].tel);
		printf("\t\t请输入家庭住址：");
		scanf("%s",g_contacts[index].add);
		
		printf("联系人修改成功！\n");
	}
	system("pause");
}
void listContact()
{
	system("cls");
	HeadShow();
	system("color 52");
	int i;
	printf("\t\tID\t姓名\t性别\t手机号码\t家庭住址\n");
	for(i=0;i<g_contacts_count;i++)
	{
		printf("\t\t%s\t%s\t%s\t%s\t%s\n",
		        g_contacts[i].no,g_contacts[i].name,g_contacts[i].sex,
				g_contacts[i].tel,g_contacts[i].add);
	}
	system("pause"); 
}
void quit()
{
	HeadShow();
	system("color 87");
	exit(0);
}

