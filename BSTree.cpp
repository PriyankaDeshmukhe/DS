#include<iostream>
#include<cstdlib>
using namespace std;
int fllag=0;
int count=0;
struct node
	{
	int data;
	struct node *left;
	struct node *right;
	};

	struct node *root;
	int search(int key)
;
void insert(int val)
	{
	if(fllag==0)
	{
	struct node *temp=new node;
	struct node *q;
	int y;

	if(root==NULL)                          //Checking is there tree??
	{
	root=temp;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	cout<<"\tElement  "<<val<<"  inserted Successfully\n";
	}
	else
	  {
	  y=search(val);                //Checking is number already exist in the tree
	   if(y==1)
	  cout<<"\n\tNumber Already exist";
	  else
	  {
	  q=root;
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
 	  while(1)                                      //Working Non recurssively
		{
			if(temp->data<q->data)
			{
				if(q->left==NULL)
				{
				q->left=temp;                  //Inserting element in left pointer of node
				cout<<"\tElement  "<<val<<"  inserted Successfully :\n";
				break;                          //Getting out of while loop
				}
				else
				{
				q=q->left;
				}
			}
			else
			{
			if(q->right==NULL)
				{
				q->right=temp;                  //Inserting element in right pointer of node
				cout<<"\tElement  "<<val<<"  inserted Successfully\n";
				break;                          //Getting out of while loop
				}
				else
				{
				q=q->right;
				}
			}
		}
	  }
	  }
	}
	else cout<<"\n\t\tThe tree is mirrored\n";
	}


void display(node *p)
	{

		if(p!=NULL)
		{
		if(p->left)  display(p->left);  //Displaying left subtree
		cout<<"  "<<p->data;            //Displaying the current position
		if(p->right)  display(p->right);//Displaying right subtree
		}
	}

void mini()
	{
	if(fllag==0)
	{
	struct node *m;
	if(root==NULL)                                  //Checking is there tree??
	cout<<"\n\tThere is not present any kind of tree";
	else
	{
	m=root;                         //Leftmost element is always min element
	while(m->left!=NULL)            //Going to lftmostelement
	{
	m=m->left;
	}
	cout<<"\n\tMinimum Valued Element is "<<m->data;//Displaying leftmost/Min element
	}
	}
	else cout<<"\n\t\tThe Tree is Mirrored\n";
	}
void mixi()
	{
	if(fllag==0)
	{
	struct node *m;
	if(root==NULL)                                  //Checking is there tree??
	cout<<"\n\tThere is not present any kind of tree";
	else
	{
	m=root;                         //Leftmost element is always min element
	while(m->right!=NULL)            //Going to lftmostelement
	{
	m=m->right;
	}
	cout<<"\n\tMaximum Valued Element is"<<m->data;//Displaying leftmost/Min element
	}
	}
	else cout<<"\n\t\tThe Tree is Mirrored\n";
	}
int depth(node *d)                              //Function to calculate depth of tree
	{
	if(fllag==0)
	{
	int ld,rd;
		if(d==NULL)
		{
		return 0;
		}
		else
		{
		ld=depth(d->left);              //Calculatng depth of left subtree
		rd=depth(d->right);             //Calculating depth of right subtree
		return (max(ld,rd)+1);          //returning the max depth from left and right
		}
	}
	else cout<<"\n\tThe Tree is Mirrored\n";
	}

/*int max(int x,int y)                            //functionto return the maximum number
	{
	if(x>=y)
	{
	return x;
	}
	else
	return y;
	}
	*/

void mirror(node *mr)                                   //Funcion to create Mirror of tree
	{

	struct node *tmp;
	if(mr!=NULL)
	    {
	    if(mr->left)  mirror(mr->left);             //Mirroring the Left subtree
	    if(mr->right) mirror(mr->right);            //Mirroring the right subtree
	    tmp=mr->left;                               //Swapping is being processing
	    mr->left=mr->right;
	    mr->right=tmp;
	    }
	    //count++;
	    //if(count%2==0)
	    //fllag=0;
	     fllag=1;
	}
int search(int key)                     //Binary search operation on tree
	{
	if(fllag==0)
	{
	int flag;
	flag=0;
	struct node *s;

		s=root;
		while(s!=NULL)
		   {
		   if(key==s->data)                     //Compairing with key
		   {
		   flag=1;
		   break;
		   }
		   else if(key<s->data)                //Checking in left subtree
		   {
		   s=s->left;
		   }
		   else
		   {
		   s=s->right;                         //Checking in right Subtree
		   }
		   }
		return flag;
	}
	else cout<<"\n\t\tThe Tree is Mirrored\n";
	}
int main()
{
int key,ch,z,val,h,found;
found=0;
cout<<"\n\t\t...........BINARY TREE..........."<<endl;
while(1)
	{
	cout<<"\n01.INSERT\n02.DISPLAY\n03.MINIMUM\n04 MAXIMUM\n05.HEIGHT";
	cout<<"\n06.MIRROR\n07.SEARCH\n08.EXIT";
	cin>>ch;
	switch(ch)
		{
		case 1:cout<<"\n\tEnter number in tree\t";
			 cin>>val;
			 insert(val);
			 break;

		case 2:cout<<endl<<"\t";
			if(root==NULL)
			cout<<"\n\tThere is no tree:";
			else
			display(root);
			break;

		case 3:mini();
				break;
		case 4:mixi();
				break;


		case 5:h=depth(root);
			 cout<<"\n\tLongest lenght of nodes is"<<h;
				break;

		case 6:if(root==NULL)
			cout<<"\n\tThere is no tree:(:(:(";
			else
			{
			mirror(root);
			 cout<<"\n\tMirror of tree is created:):):)";
			 }
			 break;

		case 7:if(root==NULL)
			cout<<"\nThere is not present any kind of tree";
			else if(fllag!=0)
			cout<<"\n\tThe Tree is Mirrored Can't Search\n";
			else
			{
			cout<<"\n\tEnter the no want to search";
			 cin>>key;
			 found=search(key);
			 if(found==1)
			cout<<"\n\tNumber is Found:):):)";
			else
			cout<<"\n\tNumber is Not Present:(:(:(";
			 }
			 break;

		case 8:exit(1);
			 break;

		default:cout<<"\nWRONG CHOICE......:(:(:(";
		}
	}
}
/*output:
 *
		...........BINARY TREE...........

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	30
	Element  30  inserted Successfully

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	10
	Element  10  inserted Successfully :

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	5
	Element  5  inserted Successfully :

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	20
	Element  20  inserted Successfully

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	40
	Element  40  inserted Successfully

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	35
	Element  35  inserted Successfully :

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	45
	Element  45  inserted Successfully

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT1

	Enter number in tree	3
	Element  3  inserted Successfully :

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT2

	  3  5  10  20  30  35  40  45
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT3

	Minimum Valued Element is 3
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT4

	Maximum Valued Element is45
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT5

	Longest lenght of nodes is4
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT7

	Enter the no want to search10

	Number is Found:):):)
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT7

	Enter the no want to search1

	Number is Not Present:(:(:(
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT6

	Mirror of tree is created:):):)
01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT7

	The Tree is Mirrored Can't Search

01.INSERT
02.DISPLAY
03.MINIMUM
04 MAXIMUM
05.HEIGHT
06.MIRROR
07.SEARCH
08.EXIT8
 */
 */
