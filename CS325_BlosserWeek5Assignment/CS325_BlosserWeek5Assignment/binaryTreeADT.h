template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType>* lLink;
	nodeType<elemType>* rLink;
};

template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&); //overload assignment operator;
	bool isEmpty() const; //determine if binary tree is empty
	void inorderTraversal() const;
	void preorderTraversal() const;
	void postorderTraversal() const;
	int treeHeight() const; //determine height of binary tree
	int treeNodeCount() const; //determine number of nodes in tree
	int treeLeavesCount() const; //determine number of leaves in tree
	void destroyTree(); //destroy binary tree

	virtual bool search(const elemType& searchItem) const = 0; //determine if searchItem in tree
	virtual void insert(const elemType& insertItem) const = 0; //insert insertItem into tree
	virtual void deleteNode(const elemtype& deleteItem) const = 0; //delete deleteItem from tree

	binaryTreeType(const binaryTreeType<elemType>& otherTree); //copy constructor
	binaryTreeType(); // default constructor
	~binaryTreeType(); //destructor

protected:
	nodeType<elemType>* root;
	void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot); // make copy of binary tree which otherTreeRoot points to
	void destroy(nodeType<elemType>* &p); //destroy binary tree to which p points
	void inorder(nodeType<elemType>* p) const; //perform inorder traversal of binary tree to which p points
	void preorder(nodeType<elemType>* p) const; //perform preorder traversal of binary tree to which p points
	void postorder(nodeType<elemType>* p) const; //perform postorder traversal of binary tree to which p points
	int height(nodeType<elemType>* p) const; //determine height of binary tree to which p points
	int max(int x, int y) const; // determine the larger of x and y
	int nodeCount(nodeType<elemType>* p) const; //determine number of nodes of binary tree to which p points
	int leavesCount(nodeType<elemType>* p) const; //determine number of leaves of binary tree to which p points
};

template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree)
{
	if (this != &otherTree)
	{
		if (root != nullptr)
			destroy(root);
		if (otherTree.root == nullptr)
			root = nullptr;
		else
			copyTree(root, otherTree.root);
	}
	return *this;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == nullptr);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = nullptr;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == nullptr)
		root = nullptr;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}



template <class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == nullptr)
		copiedTreeRoot = nullptr;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot-> lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>*& p)
{
	if (p != nullptr)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = nullptr;
	}
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p) const
{
	if (p != nullptr)
	{
		inorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType>* p) const
{
	if (p != nullptr)
	{
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType>* p) const
{
	if (p != nullptr);
	postorder(p->lLink);
	postorder(p->rLink);
	cout << p->info < " ";
}

template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType>* p) const
{
	if (p == nullptr)
		return 0;
	else
		return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}