class dSet
{
public:
	vector<int> parent, size; int count;
	dSet(int n);
	int root(int node);
	bool friends(int node1, int node2);
	void merge(int node1, int node2);
};

dSet::dSet(int n)
{
	count = n;
	parent = vector<int>(n);
	for (int i = 0; i < n; i++) parent[i] = i;
	size = vector<int>(n, 1);
}

int dSet::root(int node)
{
	while (node != parent[node]) node = parent[node];
	return node;
}

bool dSet::friends(int node1, int node2)
{
	parent[node1] = root(node1), parent[node2] = root(node2);
	return parent[node1] == parent[node2];
}

void dSet::merge(int node1, int node2)
{
	if (friends(node1, node2)) return;
	if (size[parent[node1]] > size[parent[node2]])
	{
		size[parent[node1]] += size[parent[node2]];
		size[parent[node2]]=0;
		parent[parent[node2]] = parent[node1];
	}
	else
	{
		size[parent[node2]] += size[parent[node1]];
		size[parent[node1]]=0;
		parent[parent[node1]] = parent[node2];
	}
	count--;
}
