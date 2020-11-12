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
		{{"01", "С��", "Ů", "12345678910", "����ʦ����ѧ"},
		{"02", "С����", "Ů","10987654321", "����ʦ����ѧ"},
		{"03","С����","��","18561526859","����ʦ����ѧ"}, 
		{"04","СĢ��","��","88886666222","����ʦ����ѧ"},
		{"05","���ް�","Ů","15806290348","����ʦ����ѧ"}}; 
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
			printf("��½ʧ��\n");
		}
	}
}
int chooseNumber()
{
	system("color 3D");
	int a;
	printf("\t\t*******************************************\n");
	printf("\t\t��                                       ��\n");
	printf("\t\t ��                ͨѶ¼               �� \n");
	printf("\t\t  ��                                   ��  \n");
	printf("\t\t   ************************************\n");
	printf("\t\t   ��1���뿪������......\n");
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
    	printf("\t\t������������룺");
    	scanf("%s",pwd);
    	for(i=0;i<g_self_count;i++)
    	{
	    	if(strcmp(pwd, g_self[i].pwd)==0)
	    	{
			    return 1;
			}	   
		}
	    printf("�������\n"); 
    }
    return 0;
}
void HeadShow()
{
    
    printf("      #################         ͨѶ¼����ϵͳ          #################\n");  
    printf("      -------------------------------------------------------------------\n");  
}   
void Manage()
{
	char option;
	while(1)
	{
	    system("cls");
	    system("color 4E");
	    printf("\t\t�����������������������������\n" );
	    printf("\t\t��                ͨ Ѷ ¼ �� �� ϵ ͳ                ��\n" );
		printf("\t\t��                                                    ��\n" );
		printf("\t\t��    1. �����ϵ����Ϣ          4. �޸���ϵ����Ϣ    ��\n" );
	    printf("\t\t��    2. ɾ����ϵ����Ϣ          5. �����ϵ����Ϣ    ��\n" );
	    printf("\t\t��    3. ��ѯ��ϵ����Ϣ          6. �˳�ͨѶ¼        ��\n" );
	    printf("\t\t��                                                    ��\n" );
	    printf("\t\t�����������������������������\n" );
    	printf("��ѡ��");
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
	printf("\t\t    ------------������ϵ����Ϣ-------------\n");
	printf("\t\t������ID��");
	scanf("%s",contact.no);
	for(i=0;i<g_contacts_count;i++)
	{
		if(!strcmp(contact.no,g_contacts[i].no))
		{
			n=i;
			printf("\t\t����ϵ���Ѵ��ڣ�"); 
			break;
		}
	}
	if(n==-1)
		{
			printf("\t\t������������");
			scanf("%s",contact.name);
			printf("\t\t�������Ա�");
			scanf("%s",contact.sex);
			printf("\t\t������绰���룺");
			scanf("%s",contact.tel);
			printf("\t\t�������ͥסַ��");
			scanf("%s",contact.add);
			g_contacts[g_contacts_count]=contact;
			g_contacts_count++;
			
			printf("�����ɹ�\n");
		}
	system("pause");
}
void deleteContact()             //ɾ����ϵ����Ϣ 
{
	system("cls");
	system("color 6D");
	HeadShow();
    char number[CONTACT_NO_LEN];
	int i;
	int index=-1;

	printf("\t\t********************ɾ����ϵ����Ϣ********************\n");
	printf("\t\t������Ҫɾ������ϵ��ID��");
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
		printf("����ϵ�˲�����");
	else
	{
		for(i=index;i<g_contacts_count-1;i++)
		{
			g_contacts[i]=g_contacts[i+1];
		}
		g_contacts_count--;
		printf("ɾ���ɹ���\n");
		
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
	printf("\t\t********************��ѯ��ϵ����Ϣ********************\n");
	printf("\t\t������Ҫ��ѯ����ϵ��ID��");
	scanf("%s",number);
	for(i = 0; i < g_contacts_count; i++)
	{
		if(strcmp(number, g_contacts[i].no)==0)
		{
			system("cls"); 
			printf("\t\tID\t����\t�Ա�\t�ֻ�����\t��ͥסַ\n");
			printf("\t\t%s\t%s\t%s\t%s\t%s\n",
			       g_contacts[i].no, g_contacts[i].name, g_contacts[i].sex,
				    g_contacts[i].tel,g_contacts[i].add);
					break;
		}	 
	}
	if(i==g_contacts_count)
		{
			printf("����ϵ�˲�����");
		}
	system("pause");
}
void changeContact()                 //�޸���ϵ����Ϣ 
{
	char temp[CONTACT_NO_LEN];
	int i;
	int index=-1;
	
	system("cls");
	system("color 18");
	printf("\t\t*******************�޸���ϵ����Ϣ********************\n");
	printf("\t\t������Ҫ�޸ĵ���ϵ��ID��");
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
	printf("�˻������ڣ�\n");
	else
	{
		printf("\t\t�������µ��˻���Ϣ��");
		printf("������ID��"); 
		scanf("%s",g_contacts[index].no);
		printf("\t\t������������");
		scanf("%s",g_contacts[index].name);
		printf("\t\t�������Ա�");
		scanf("%s",g_contacts[index].sex);
		printf("\t\t������绰���룺");
		scanf("%s",g_contacts[index].tel);
		printf("\t\t�������ͥסַ��");
		scanf("%s",g_contacts[index].add);
		
		printf("��ϵ���޸ĳɹ���\n");
	}
	system("pause");
}
void listContact()
{
	system("cls");
	HeadShow();
	system("color 52");
	int i;
	printf("\t\tID\t����\t�Ա�\t�ֻ�����\t��ͥסַ\n");
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

