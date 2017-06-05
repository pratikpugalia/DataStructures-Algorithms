// Trie Search and Insert queries
// Insert and search in O(n) where n is length of string

#include<bits/stdc++.h>

using namespace std;


struct node
{
	char val;
	node* point[26];
	int end;
};

void init(node* temp,char vl)
{
	temp->val=vl;
	temp->end=0;
	for (int i = 0; i <26; ++i)
	{
		temp->point[i]=NULL;
	}
}

void insert(string a,node* curr)
{
	int ind=-1;
	for (int i = 0; i <a.length(); ++i)
	{	
		ind=a[i]-'a';
		if(curr->point[ind]==NULL)
		{
			node* tmp=new node;
			init(tmp,a[i]);
			curr->point[ind]=tmp;
		}
		curr=curr->point[ind];
	}
	curr->end+=1;
}

int query(string a,node *curr)
{
	int ind=-1;
	for (int i = 0; i <a.length(); ++i)
	{	
		ind=a[i]-'a';
		if(curr->point[ind]==NULL)
		{
			return 0;
		}
		curr=curr->point[ind];
	}
	if(curr->end!=0)
	return 1;
	return 0;
}

int main()
{
	int n,q;
	string x;
	cin>>n;
	node* root=new node;

	init(root,'.');

	for (int i = 0; i <n; ++i)
	{

		cin>>x;
		node* trav=root;
		insert(x,trav);
	
	}

	cin>>q;

	for (int i = 0; i < q; ++i)
	{
		cin>>x;
		node* trav=root;
		if(query(x,trav))
			cout<<"FOUND"<<endl;
		else
			cout<<"NOT FOUND"<<endl;
	}
}