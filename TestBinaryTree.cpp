#include "BinaryTree.h"		// ����������
struct grid
{
	int a;//�Ƿ�����ͨ
	int b;//������
	int c;//������
};
int main(void)
{
	grid on[12][12];
	int i,j;
	for(i=0;i<10;i++)
	{
		on[i][0].a=1;
		on[i][11].a=1;
		on[0][i].a=1;
		on[0][i].a=1;
	}
	for(i=0;i<12;i++)
		for(j=0;j<12;j++)
		{
				on[i][j].b=i;
				on[i][j].c=j;//�����Թ�����
		}
	for(i=1;i<11;i++)
		for(j=1;j<11;j++)
		{
				cin>>on[i][j].a;//�����Թ�����
		}
	TriaryTree<grid> bt;

	bt = CreateTriaryTreeon(on,1,1);           // ����������
	cout << "�ɾ���on[10][10]����������" << endl;
	DisplayBTWithTreeonShape<grid>(bt);
	cout<<endl;
	system("PAUSE");
	cout<< "����Թ�������·��:"<<endl;
	DisplayBTWithTreeonnShape<grid>(bt);
	cout << endl;

	system("PAUSE");

	return 0;
}

