#include "BinaryTree.h"		// 三叉链表类
struct grid
{
	int a;//是否能走通
	int b;//横坐标
	int c;//纵坐标
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
				on[i][j].c=j;//输入迷宫矩阵
		}
	for(i=1;i<11;i++)
		for(j=1;j<11;j++)
		{
				cin>>on[i][j].a;//输入迷宫矩阵
		}
	TriaryTree<grid> bt;

	bt = CreateTriaryTreeon(on,1,1);           // 构造三叉树
	cout << "由矩阵on[10][10]构造三叉树" << endl;
	DisplayBTWithTreeonShape<grid>(bt);
	cout<<endl;
	system("PAUSE");
	cout<< "输出迷宫的所有路径:"<<endl;
	DisplayBTWithTreeonnShape<grid>(bt);
	cout << endl;

	system("PAUSE");

	return 0;
}

