#include <iostream>
#include <vector>
#include<queue>
#include<list>
#include<map>
#include<stack>
#include<unordered_map>
#include<set>
#include<algorithm>
#include <string>
using namespace std;

void two_pointers(int (&nums)[])
{
	int* first_ptr = &nums[0];
	int* second_ptr = &nums[1];

	for (int i = 1; i <= 17; i++)
	{
		if (*first_ptr != *second_ptr)
		{
			first_ptr++;
			*first_ptr = *second_ptr;
			
		}
		if (second_ptr < &nums[16])
			second_ptr++;
		
	}
	for (int i = 0; i < 17; i++)
	{
		if (*first_ptr == nums[i])
		{
			cout << i << endl;
			break;
		}
		
	}
}

void sliding_window(int arr[], int num)
{
	int max = 0;
	int tempMax = 0;

	for (int i = 0; i < num; i++)
	{
		max += arr[i];
	}	
	tempMax = max;
	for (int i = num; i < 17; i++)
	{
		tempMax = tempMax - arr[i - num] + arr[i];
		if (tempMax > max)
			max = tempMax;
	}
	cout << max << endl;
}

int recursive_function(int num)
{
	if (num == 0)
	{
		cout << "END!" << endl;
		return 0;
	}
	cout << num << "\n";
	num--;
	recursive_function(num);
}

int factorial(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num * factorial(num - 1);
}

int collect_odd_values(int num1)
{
	vector<int> results;

		if (num1 == 0)
		{
			return 1;
		}
		if (num1 % 2 !=0)
		{
			results.push_back(num1);
		}
		return collect_odd_values(num1 - 1);
	
}

 void linear_search(int arr [], int value)
{
	int flag = 0;
	for (int i = 0; i < 17; i++)
	{
		if (arr[i] == value)
		{
			flag = 1;
			break;
		}
		else if (arr[i] != value)
		{
			flag = 0;
			continue;
		}

	}
	if (flag == 1)
	{
		cout << "found!";
	}
	else
		cout << "not found!";
}

 int linear_search2(int arr[], int value)
 {
	 for (int i = 0; i < 17; i++)
	 {
		 if (arr[i] == value)return i;
	 }
	 return 0;
 }

 int binary_search(int arr[], int value)
 {
	 int left = 0;
	 int right = 17;
	 int middle = (left + right) / 2;

	 if (value > arr[16] || value < arr[0]) return -1;

		while (left <= right)
		{
		 if (arr[middle] == value)return middle;
		 if (value < arr[middle])right = middle - 1;
		 else left = middle + 1;
		 middle = (left + right) / 2;
		}
		return -1;
 }

 int binary_search2(int arr[], int val)
 {
	 int left = 0;
	 int right = 16;
	 int middle = (left + right) / 2;
	 if (val> arr[16] || val < arr[0])
	 {
		 return -1;
	 }
	 while (left <= right && arr[middle] != val)
	 {
		 if (val < arr[middle]) right = middle - 1;
		 else left = middle + 1;
		 middle = (left + right) / 2;
	 }
	 return arr[middle] == val ? middle : -1;
 }

 void string_search(string word1 , string key)
 {
	 int count = 0;
	 for (int i = 0; i < word1.size(); i++)
	 {
		 for (int j = 0; j <= key.size(); j++)
		 {
			 if (key[j] != word1[i + j])break;
			 if (j == key.size() - 1)count++;
		 }
	 }
	 count == 0 ? cout << "not found!" : cout << "found " << count << " times";
 }

 void swap(int &x, int &y)
 {
	 int temp = x; 
	 x = y;
	 y = temp;

 }

 void multiple_pointers(int arr[])
 {
	 int ptr1 = 0;
	 int ptr2 = 6;

	 while (ptr1 <= ptr2)
	 {
		 if (arr[ptr1] + arr[ptr2] == 0)
		 {
			 cout << "found " << arr[ptr1] << " , " << arr[ptr2];
			 ptr1++;
			 ptr2--;
		 }
		 else
		 {
			 ptr1++;
			 ptr2--;
		 }
	 }
 }

 void bubble_sort(int arr[]) 
 {
	 for (int i = 16; i >= 0; i--)
	 {
		 bool no_swaps = true;
		 for (int j = 0; j < i - 1; j++)
		 {
			int k = j + 1;
			if (arr[j] > arr[k])
			{
				swap(arr[j], arr[k]);
				no_swaps = false;
				continue;
			}
		 }
		 if (no_swaps == true) break;
	 }
	 //for (int i = 0; i < 17; i++) cout << arr[i] << endl;
 }

 void selection_sort(int arr[])
 {
	 for (int i = 0; i < 16; i++)
	 {
		 int min = i;
		 for (int j = i + 1; j < 17; j++)
		 {
			 if (arr[j] < arr[min])
			 {
				 min = j;
				 continue;
			 }
		 }
		if (i != min) swap(arr[min], arr[i]);
	 }
	 for (int i = 0; i < 17; i++) cout << arr[i] << endl;
 }

 void insertion_sort(int arr[])
 {
	 for (int i = 1; i < 17; i++)
	 {
		 int curVal = arr[i];
		 for (int j = i - 1; (j >= 0 && curVal < arr[j]); j--)
		 {
			 arr[j + 1] = arr[j];
			 arr[j] = curVal;
		 }
	 }
	 for (int i = 0; i < 17; i++) cout << arr[i] << endl;
 }

 void reverse_arr(int arr[])
 {
	 int ptr1 = 0;
	 int ptr2 = 16;
	 while (ptr1 != ptr2)
	 {
		 swap(arr[ptr1], arr[ptr2]);
		 ptr1++;
		 ptr2--;
	 }
	 for (int i = 0; i < 17; i++) cout << arr[i] << endl;
 }

 void merge_two_sorted_arrays(int arr[], int l, int r, int m)
 {
	 int n1 = m - l + 1;
	 int n2 = r - m;

	 vector <int> arr1, arr2;
	 for (int i = 0; i < n1; i++)
	 {
		 arr1.push_back(arr[l + i]);
	 }
	 for (int i = 0; i < n2; i++)
	 {
		 arr2.push_back(arr[m + i + 1]);
	 }
	 /*for (auto elm : arr1) cout << elm << " ";
	 cout << endl;
	 for (auto elm : arr2) cout << elm << " ";
	 cout << endl;
	 cout << endl;*/
	 int i = 0, j = 0, k = l;
	 while (i < arr1.size() && j < arr2.size() )
	 {
		 if (arr1[i] < arr2[j])
		 {
			 arr[k] = arr1[i];
			 k++;
			 i++;
		 }
		 else
		 {
			 arr[k] = arr2[j];
			 j++;
			 k++;
		 }
		 
	 }
	 while (j < arr2.size())
	 {
		 arr[k] = arr2[j];
		 j++;
		 k++;
	 }
	 while (i < arr1.size())
	 {
		 arr[k] = arr1[i];
		 i++;
		 k++;
	 }
	 //for (int i = 0; i < merged.size(); i++) cout << merged[i] << endl;
 }
 void merge_sort(int arr[], int l, int r)
 {
	 int m;
	 if (l < r) 
	 {
		 m = (l + r) / 2;
		 merge_sort(arr, l , m);
		 merge_sort(arr, m+1 , r);
		 merge_two_sorted_arrays(arr, l, r, m);
	 }

 }

 void up_to_sum(int arr[], int target) 
 {
	 // not the ideal soluion / messed up;
	 int max = 0;
	 vector <vector <int>> results{ {0,0} };
	 for (int i =0; i < 2; i++)
	 {
		 max += arr[i];
		 
	 }

	 if (max == target)
	 {

		 results[0][0] = arr[0];
		 results[0][1] = arr[1];
	 }

 	 int j = 1;
	 for (j; j < 17; j++)
	 {
		 max = arr[j] + arr[j + 1];
		 if (max == target)
		 {
			 results.push_back({ arr[j] , arr[j + 1] });
		 }
	 }
	 for (auto elm : results)
	 {
		 cout << "[ " << elm[0] << " , " << elm[1] << " ]";
	 }
 }

 int multiple_pointers2(int arr[])
 {
	 int ptr1 = 0, ptr2 = 1;

	 for (int i = 0; i < 17; i++)
	 {
		 if (arr[ptr2] != arr[ptr1] &&ptr2 < 17)
		 {
			 ptr1++;
			 arr[ptr1] = arr[ptr2];
			 ptr2++;
		 }
		 else ptr2++;
	 }
	 return ptr1 +1;
 }

 int partioning(vector <int> &arr, int start, int end)
 {
	 int pivot = arr[end];
	 int pivot_index = start;
	 for (int i = start; i <= end; i++)
	 {
		 if (arr[i] < pivot)
		 {
			 swap(arr[i] , arr[pivot_index]);
			 pivot_index++;
		 }
	 }
	 swap(arr[end], arr[pivot_index]);
	 return pivot_index;
 }
 int partioning2(vector <int> arr, int start, int end)
 {
	 int mid = (start + end )/ 2;
	 int pivot;
	 int pivot_index = start;
	 if (arr[start] > arr[mid]) swap(arr[start] , arr[mid]);
	 if (arr[end] < arr[mid]) swap(arr[end] , arr[mid]);
	 pivot = arr[end];
	 for (int i = start; i <= end; i++)
	 {
		 if (arr[i] < pivot)
		 {
			 swap(arr[i], arr[pivot_index]);
			 pivot_index++;
		 }
	 }
	 swap(arr[end], arr[pivot_index]);
	 return pivot_index;
 }
 void quick_sort(vector <int> &arr, int start, int end)
 {
	 if (start < end)
	 {
		 int piv = partioning(arr, start, end);
		 quick_sort(arr, start, piv -1);
		 quick_sort(arr, piv + 1, end);

	 }
 }

 vector<pair<int, int>> mult_pt(vector <int> &arr, int target)
 {
	 int p1 = 0;
	 int p2 = arr.size() -1 ;
	 vector < pair <int, int> > res;
	 while (p1 < p2)
	 {
		 if (arr[p1] + arr[p2] == target)
		 {
			res.push_back(make_pair(arr[p1], arr[p2]));
			p2--;
			p1++;
		 }
		 else if (arr[p1] + arr[p2] < target)
		 {
			 p1++;
			 continue;
		 }
		 else if (arr[p1] + arr[p2] > target)
		 {
			 p2--;
			 for (int i = p1; i >= 0; i--)
			 {
				 if (arr[i] + arr[p2] == target)
				 {
					 res.push_back(make_pair(arr[i], arr[p2]));
					 p2--;
					 p1++;
				 }
				 else if (arr[i] + arr[p2] > target)
				 {
					 continue;
				 }
				 else
				 {
					 break;
				 }
			 }
		 }
	 }
	 return res;
 }

 vector <char> get_longest_string(string para, int *longestLength)
 {
	 struct word
	 {
		 vector <char> letters;
		 int length;

		 word (int length)
			 :length{ length } {}

		 ~word()
		 {
			 letters.clear();
			 length = NULL;
		 }
	 };
	 vector <word> words;
	 int i = 0;
	 char curr;
	 word word1( 0);

	 for (i ; i < para.size(); i++)
	 {
		 curr = para[i];
		 if (curr == ' ')
		 {
			 words.push_back(word1);
			 word1.letters.clear();
			 word1.length = 0;
		 }
		 else 
		 {
			 word1.letters.push_back(curr);
			 word1.length++;
		 }
		 if (i == para.size() -1 )
		 {
			 words.push_back(word1);
			 word1.letters.clear();
			 word1.length = 0;
		 }
	 }

	 int longestIdx = -1;
	 int longest = -1;
	 for (int i = 0; i < words.size(); i++)
	 {
		 if (words[i].length > longest)
		 {
			 longest = words[i].length;
			 longestIdx = i;
		 }
	 }
	 *longestLength = longest;
	 return words[longestIdx].letters;
 }

 class SinglyLinkedList
 {
 public:
	 struct Node
	 {
		 int val;
		 Node* next;
		 Node()
		 {
			 val = NULL;
			 next = NULL;
		 }
		 Node(int val)
			 : val{ val }, next{ NULL }{}
		 Node(int val, Node* next)
			 : val{ val }, next{ next } {}
	 };
	 struct Search
	 {
		 Node* result;
		 int index;

		 Search(Node* result, int index)
			 :result{ result }, index{ index } {}
		 Search(int index)
			 : result{ NULL }, index{ index } {}
	 };

	 Node* head;
	 Node* tail;
	 int length = 1;

	 SinglyLinkedList()
	 {
		 head = NULL;
		 tail = NULL;
	 }
	 void insert_to_front(int val)
	 {
		 Node* temp = new Node(val, head);

		 if (head == NULL)
		 {
			 temp->next = NULL;
			 temp->val = val;
			 head = temp;
			 tail = temp;
			 length++;
		 }
		 else
		 {
			 head = temp;
			 length++;
		 }

	 }
	 void insert_to_middle(int val)
	 {
		 Node* new_val = new Node(val);
		 Node* temp = head;
		 for (int i = 1; i < length / 2; i++)
		 {
			 temp = temp->next;
		 }
		 new_val->next = temp->next;
		 temp->next = new_val;
		 length++;


	 }
	 void insert_by_val(int pos_val, int val)
	 {
		 Node* new_val = new Node(val);
		 Node* temp = head;
		 if (head != NULL)
		 {
			 while (temp->val != pos_val)
			 {
				 temp = temp->next;
			 }
			 new_val->next = temp->next;
			 temp->next = new_val;
			 length++;
		 }
		 else cout << "sorry, the list is empty!";
	 }
	 void insert_to_back(int val)
	 {
		 Node* temp = new Node(val);

		 if (head == NULL)
		 {
			 head = temp;
			 tail = temp;
			 length++;
		 }
		 else
		 {
			 tail->next = temp;
			 tail = tail->next;
			 length++;
		 }
	 }
	 void delete_first()
	 {
		 Node* temp = head;
		 head = head->next;
		 delete temp;
		 length--;

	 }
	 void delete_by_val(int val)
	 {
		 Node* temp = head;
		 if (head->val == val)
		 {
			 delete_first();
			 
		 }
		 else if (tail->val == val)
		 {
			 delete_last();
		 }
		 else
		 {
			 while (temp->next->val != val)
			 {
				 temp = temp->next;
			 }
			 Node* deleted = temp->next;
			 temp->next = temp->next->next;
			 delete deleted;
			 length--;
		 }

	 }
	 void delete_middle()
	 {
		 Node* temp =head; 
		 for (int i = 1; i < (length / 2) - 1; i++)
		 {
			 temp = temp->next;
		 }
		 Node* del = temp->next;
		 temp->next = del->next;
		 delete del;
		 length--;
	 }
	 void delete_last()
	 {
		 Node* current = head;
		 while (current->next->next != NULL)
		 {
			 current = current->next;
		 }
		 delete (current->next);
		 length--;
		 current->next = NULL;
		 tail = current;
	 }
	 Search search(int val)
	 {
		 Node *temp = head;
		 int i = 0;
		 for (i ; i < length-1 && temp->val != val; i++)
		 {
			 temp = temp->next;
		 }
		 return i != length-1 ? Search(temp,i) : Search(i);
	 }
	 void set(int find, int val)
	 {
		 Search result = search(find);
		 if (result.result == NULL) cout << "not found!";
		 else
			 result.result->val = val;
	 }
	 void reverse()
	 {
		 Node* curr = head; 
		 head = curr;
		 head = tail;
		 tail = curr;
		 Node* next;
		 Node* prev = NULL;
		 while (curr!= NULL)
		 {
			 next = curr->next;
			 curr->next = prev;
			 prev = curr; 
			 curr = next;
		 }

	 }
	 void reverse_recursive(Node* curr = NULL, Node* next = NULL , Node* prev = NULL)
	 {
		 if (curr->next == NULL)
		 {
			 curr->next = prev;
			 Node* temp = head;
			 head = temp;
			 head = tail;
			 tail = temp;
			 return;
		 }
		
		 curr->next = prev;
		 prev = curr; 
		 curr = next;
		 next = curr->next;
		 reverse_recursive(curr, next, prev);
		 
	 }
	 
 };

 class linkedList
 {
 public:
	 //Attributes

	 struct Node
	 {
		 int data;
		 Node* next = nullptr;

		 Node()
			 :data{ NULL }, next{ NULL } {}
		 Node(int data, Node*next)
			 :data{ data }, next{ next } {}
		 Node(int data)
			 :data{ data }, next{ NULL } {}
	 };

	 Node* head = NULL;
	 Node* tail = NULL; 
	 int length = 0;


	 //Behaviours

	 Node* get(int val)
	 {
		 if (val == head->data)
		 {
			 return head;
		 }

		 Node* result;
		 Node* temp = head;
		 while (temp->next != NULL && temp->next->data != val)
		 {
			 temp = temp->next;
		 }
		 if (temp->next != NULL)
		 {
			 result = temp->next;
			 return result;
		 }
		 else
		 {
			 return NULL;
		 }
	 }
	 void set(int replace, int val)
	 {
		 Node *result = get(replace);
		 result->data = val;
	 }
	 void push(int val)
	 {
		 Node* temp = new Node(val);
		 if (head == NULL)
		 {
			 head = temp;
			 tail = temp;
			 length++;
		 }
		 else
		 {
			 tail->next = temp;
			 tail = temp;
			 length++;
		 }
	 }
	 void pop()
	 {
		 Node* temp = head;
		 while (temp->next->next != NULL)
		 {
			 temp = temp->next; 
		 }
		 delete (temp->next);
		 length--;
		 tail = temp;
		 tail->next = NULL;
	 }
	 void pop2()
	 {
		 Node* pre = head;
		 Node* temp = pre->next;

		 while (temp->next != NULL)
		 {
			 pre = pre->next;
			 temp = pre->next;
		 }
		 pre->next = NULL;

		 delete temp;
		 length--;
		 tail = pre;
	 }
	 void shift(int val)
	 {
		 Node* temp = new Node(val, head);
		 head = temp;
		 length++;
	 }
	 void unshift()
	 {
		 Node* temp = head; 
		 head = head->next;
		 delete temp;
		 length--;
	 }
	 void del(int place)
	 {
		 if (place == head->data)
		 {
			 unshift();
		 }
		 if (place == tail->data)
		 {
			 pop();
		 }
		 else
		 {
			 Node* temp = head;
			 while (temp->next->data != place)
			 {
				 temp = temp->next;
			 }
			 Node* del = temp->next;
			 temp->next = temp->next->next;
			 delete del;
		 }
	 }
	 void insert(int place, int val)
	 {
		 if (place == tail->data)
		 {
			 push(val);
		 }
		 else if (place == head->data)
		 {
			 Node* temp = new Node(val, head->next);
			 head->next = temp;
			 length++;
		 }
		 else
		 {
			 Node* temp = head;
			 for (int i = 0; i < length; i++)
			 {
				 if (temp->data != place)
				 {
					 temp = temp->next;
				 }
			 }
			 Node* add = new Node(val, temp->next);
			 temp->next = add;
			 length++;
		 }
	 }
	 void reverse()
	 {
		 Node* curr = head;
		 Node* next = head->next;
		 Node* prev = NULL;
		 while (curr!= NULL)
		 {
			 next = curr->next;
			 curr->next = prev;
			 prev = curr;
			 curr = next;
		 }
		 Node* temp = head; 
		 head = tail;
		 tail = temp;
	 }
 };

 class doubelyLinkedList 
 {
	 
	 // Attribues 

	 struct node // struct for each node in the list 
	 {
		 int data; 
		 node* next; 
		 node* prev;

		 node() 
			 : data{ NULL }, next{ NULL }, prev{ NULL } {}

		 node(int Data)
			 :data{ Data }, next{ NULL }, prev{ NULL } {}

		 node(int Data, node* pre, node* nex) // Node constructor
			 : data{ Data }, prev{ pre }, next{ nex } {}
	 };

	 node* head = NULL; // pointer to the first element in the list
	 node* tail = NULL; // pointer to the last element in ther list
	 int length = 0; // length of the list 

 public:
	 // Behaviours 

	 void push(int val) // push item to the end
	 {
		 node* temp = new node(val,tail,NULL);
		 if (head == NULL)
		 {
			 head = temp; 
			 tail = temp;
		 }
		 tail->next = temp; 
		 tail = temp;
		 length++;
	 } 
	 void pop() //delete item from the end
	 {
		 node* del = tail; 
		 tail = tail->prev;
		 tail->next = NULL;
		 delete del; 
		 length--;
	 }
	 void shift() // delete item from the front
	 {
		 node* del = head;
		 head = head->next; 
		 head->prev = NULL; 
		 delete del;
		 length--;
	 }
	 void unshift(int val) // add item to the front
	 {
		 node* temp = new node(val, NULL, head);
		 head->prev = temp;
		 head = temp;
		 length++;
	 }
	 int set(int val, int replace)
	 {
		 node* temp = head;
		 while (temp->next != NULL && temp->data != replace)
		 {
			 temp = temp->next;
		 }
		 if (replace == tail->data && temp == tail)
		 {
			 temp->data = val;
			 return 2;
		 }
		 else if (temp != tail)
		 {
			 temp->data = val;
			 return 1;
		 }
		 else
		 {
			 return 0;
		 }
	 }
	 bool get(int val)
	 {
		 node* temp = head;
		 while (temp->next != NULL && temp->data != val)
		 {
			 temp = temp->next;
		 }
		 if (temp == tail && temp->data == val)
		 {
			 return true;
		 }
		 else if (temp != tail && temp->data == val)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }
	 void insert(int val, int place )
	 {
		 node* temp = head;
		 while (temp->next != NULL && temp->data != place)
		 {
			 temp = temp->next;
		 }
		 if (temp == tail && temp->data == place)
		 {
			 push(val);
		 }
		 else if (temp != tail && temp->data == place)
		 {
			 node* insert = new node(val,temp,temp->next);
			 temp->next = insert;
			 insert->next->prev = insert;
		 }

	 }
	 void del(int val)
	 {
		 node* temp = head;
		 while (temp->next != NULL && temp->data != val)
		 {
			 temp = temp->next;
		 }
		 if (temp == tail && temp->data == val)
		 {
			 pop();
		 }
		 else if (temp == head)
		 {
			 shift();
		 }
		 else if (temp != tail && temp->data == val)
		 {
			 node* del = temp; 
			 temp->prev->next = temp->next;
			 temp->next->prev = temp->prev;
			 delete del;
		 }
	 }

 };

 class stack1
 {
	 struct node
	 {
		 int data;
		 node* next;

		 node(int Data)
			 : data{ Data }, next{ NULL } {}

		 node(int Data, node* Next)
			 : data{ Data }, next{ Next } {}
	 };

	 int length = 0;
	 node* first = NULL;

 public:

	 stack1()
		 : length{ 0 }, first{ NULL } {}

	 int push(int val)
	 {
		 if (first == NULL)
		 {
			 node* temp = new node(val, first);
			 first = temp; 
			 length++;
			 return 0;
		 }

		 node* temp = new node(val, first);
		 first = temp;
		 length++;
	 }

	 int pop()
	 {
		 if (first == NULL)
		 {
		 return 0;
		 }

		 else if (first->next == NULL)
		 {
			 node* del = first; 
			 delete del; 
			 first = NULL;
			 length--;
			 return 0;
		 }
		 

		 node* del = first; 
		 first = first->next;
		 delete del;
		 length--;
	 }
 };

class queue1
 {
	 struct node 
	 {
		 int val; 
		 node* next;
		 
		 node (int Val)
			 : val{ Val }, next{ NULL } {}

		 node (int Val, node* Next)
			 : val{ Val }, next{ Next } {}
	 };

 
 public: 
	 node* first = NULL;
	 node* last = NULL; 
	 int size;
	 queue1()
		 : first{ NULL }, last{ NULL }, size{ 0 } {};

	 void push(int val)
	 {
		 node* temp = new node(val, NULL);
		 if (first == NULL)
		 {
			 first = temp; 
			 last = temp;
			 size++;
		 }
		 else
		 {
			 last->next = temp;
			 last = temp;
			 size++;
		 }
	 }

	 void pop()
	 {
		 if (first == last )
		 {
			 first = NULL;
			 last = NULL;
			 size--;
		 }

		 else
		 {
		 node* del = first; 
		 first = first->next;
		 delete del;
		 size--;
		 }
	 }
 };

 class BST 
 {
 public: 
	 struct node
	 {
		 int val; 
		 node* left; 
		 node* right;

		 node (int Val)
			 : val{ Val }, left{ NULL }, right{ NULL } {}
	 };

	 node* root;

	BST()
		 :root{ NULL } {};

	BST(node* Root)
		 :root{ Root } {}


	 int insert(int val)
	 {
		 node* temp = new node(val);

		 if (root == NULL)
		 {
			 root = temp;
			 return 0;
		 }
		 //else
			 node* search = root;
			 while (true)
			 {
				 if (val == search->val)
				 {
					 cout << "You cant insert a number that is already in their: " << search->val << endl;
					 return 0;
				 }
				 else if (val < search->val)
				 {
					 if (search->left == NULL)
					 { 
						search->left = temp;
						return 0;
					 }
					 search = search->left;
				 }
				 else
				 {
					 if (search ->right == NULL)
					 {
						 search->right = temp;
						 return 0;
					 }
					 search = search->right;
				 }
			 }
	 }

	 int find(int val)
	 {
		 node* search = root; 
		 while (true)
		 {	 
			 if (root == NULL)
			 {
				 cout << "There is no values in the tree!" << endl;
				 return 0;
			 }

			 if (search->val == val)
			 {
				 cout << "Found! " << endl;
				 return val;
			 }


			 else if (val < search-> val)
			 {
				 if (search->left == NULL)
				 {
						 cout << "Value not found! " << endl;
						 return 0;
				 }
				 search = search->left;
			 }

			else
			{
				if (search -> right == NULL)
				{
					 
						 cout << "Value not found! " << endl;
						 return 0;
				}
				search = search->right;
			}
		 }
	 }

	 int find2(int val)
	 {
		 node* curr = root; 
		 while (curr)
		 {

			 if (root == NULL)
			 {
				 cout << "The tree is empty! " << endl;
				 return 0;
			 }

			 if (val > curr->val)
			 {
				 curr = curr->right;
			 }
			 else if (val < curr-> val)
			 {
				 curr = curr->left;
			 }
			 else 
			 {
				 cout << "Found!" << endl;
				 return val;
			 }
		 }
		 cout << "Not Found!" << endl;
		 return 0;
	 }
 };

 class tree
 {
 public:
	 struct node
	 {
		 int val; 
		 node* left; 
		 node* right; 

		 node()
			 : val{ NULL }, left{ NULL }, right{ NULL } {}
		 node(int val )
			 : val{ val }, left{ NULL }, right{ NULL }{}
	 };

	 node* root = NULL; 

	 int insert(int val)
	 {
		 node* temp = new node(val);
		 node *search = root;
		 while (true)
		 {
			if (root == NULL)
			{
				 root = temp;
				 return 0;
			}
			else if (val < search->val )
			{
				 if (search->left == NULL)
				 {
					 search->left = temp;
					 return 0;
				 }
				 search = search->left;
			}
			else if (val > search->val)
			{
				 if (search->right == NULL)
				 {
					 search->right= temp;
					 return 0;
				 }
				 search = search->right;
			}
			else
			{
				 cout << "You can't put duplicates in a tree" << endl;
				 return 0;
			}
		 }
	 }

	 node find(int val)
	 {
		 node* search = root; 

		 while (true)
		 {
			 if (root == NULL)
			 {
				 cout << "There's no elements in the tree yet." << endl; 
				 return 0;
			 }

			 else if (val == root->val)
			 {
				 return *root;
			 }

			 else if (search->val == val)
			 {
				 cout << "Found!" << endl; 
				 return *search;
			 }

			 else if (val < search->val)
			 {
				 if (search -> left == NULL)
				 {
					 cout << "Not found!" << endl;
					 return NULL;
				 }
				 search = search->left;
			 }
			 else
			 {
				 if (search ->right == NULL)
				 {
					 cout << "Not found!" << endl;
					 return NULL;
				 }
				 search = search->right;
			 }
		 }
	 }

	 vector <node> bfsIterative()
	 {
		 queue <node> que;
		 vector <node> visited;
		 node* last;
		 que.push(*root);
		 while (que.size() != 0)
		 {
			 visited.push_back(que.front());
			 que.pop();
			 last = &(visited.back());
			 if (last->left != NULL)
			 {
				 que.push(*(last->left));
			 }
			
			 if (last->right != NULL)
			 {
				 que.push(*(last->right));
			 }
			 
		 }
		 return visited;
	 }

	 queue <node> q;
	 vector <node> v;
	 
	 void pp() //simple function to put the root at the begining of the queue
	 {
		 q.push(*root);
	 }  

	 void bfsRecursive()// the recursive function itself
	 {
		 if (q.empty())
		 {
			 return;
		 }
		 v.push_back(q.front());
		 q.pop();
		 node* last = &v.back();
		 if (last->left != NULL)
		 {
			 q.push(*last->left);
		 }
		 if (last->right != NULL)
		 {
			 q.push(*last->right);
		 }
		 bfsRecursive();
	 }

	 void dfsprehelper(node temp, vector <node> &i)
	 {
		 i.push_back(temp);
		 if (temp.left != NULL)
		 {
			 dfsprehelper(*temp.left, i);
		 }
		 if (temp.right != NULL)
		 {
			 dfsprehelper(*temp.right, i);
		 }
	 }

	 void dfsposthelper(node temp, vector<node> &i)
	 {
		 if (temp.left != NULL)
		 {
			 dfsposthelper(*temp.left, i);
		 }
		 if (temp.right != NULL)
		 {
			 dfsposthelper(*temp.right, i);
		 }
		 i.push_back(temp);
	 }

	 void dfsinorderhelper(node temp, vector<node>& i)
	 {
		 if (temp.left != NULL)
		 {
			 dfsinorderhelper(*temp.left, i);
		 }
		 i.push_back(temp);
		 if (temp.right != NULL)
		 {
			 dfsinorderhelper(*temp.right, i);
		 }
	 }

	 void dfspre()
	 {
		 node* curr = root; 
		 vector <node> visited; 		 
		 dfsprehelper(*root,visited);
	 }

	 void dfspost()
	 {
		 node* curr = root;
		 vector <node> visited;
		 dfsposthelper(*root, visited);
	 }

	 void dfsinorder()
	 {
		 node* curr = root;
		 vector <node> visited;
		 dfsinorderhelper(*root, visited);
	 }
 };

 class maxHeap
 {

	 vector <int> heapTree; 

	 void bubbleUp(int val, vector<int> &arr)
	 {
		 if (arr.size() == 1)
		 {
			 return;
		 }

		 int parent = ((arr.size() - 2) / 2);
		 int currIdx = arr.size() - 1;
		 while (arr[currIdx] > arr[parent])
		 {
			 if (currIdx < 0)
			 {
				 break;
			 }
			 swap(arr[currIdx], arr[parent]);
			 currIdx = parent;
			 parent = (currIdx - 1) / 2;
		 }
	 }
	 void bubbleDown(int val, vector <int> &arr)
	 {
		 int parent = 0;
		 int child1 = (parent * 2) + 1;
		 int child2 = (parent * 2) + 2;
		 int compare;
		 while (true)
		 {
			 if (arr[child1] < arr[child2])
			 {
				 compare = child2;
			 }
			 else
			 {
				 compare = child1;
			 }
			 if (arr[parent] < arr[compare])
			 {
				 swap(arr[parent], arr[compare]);
				 parent = compare;

				 if ((parent * 2) + 1 < arr.size())
				 {
					 child1 = (parent * 2) + 1;
				 }
				 else
				 {
					 return;
				 }
				 if ((parent * 2) + 2 < arr.size())
				 {
					child2 = (parent * 2) + 2;
				 }
				 else
				 {
					 if (arr[parent] < arr[child1])
					 {
						 swap(arr[parent], arr[child1]);
						 return;
					 }
					 return;
				 }
			 }
			 //else if (arr[parent] < arr[child2])
			 //{
				// swap(arr[parent], arr[child2]);
				// parent = child2;
				// child1 = (parent * 2) + 1;
				// child2 = (parent * 2) + 2;
			 //}
			 else
			 {
				 return;
			 }
		 }
	 }

 public:
	 void insert(int val)
	 {
		 heapTree.push_back(val);
		 bubbleUp(val, heapTree);
	 }

	 void extractMax()
	 {
		 swap(heapTree[0], heapTree[heapTree.size() - 1]);
		 heapTree.erase(heapTree.begin() + heapTree.size() - 1);
		 bubbleDown(heapTree[0],heapTree);
	 }
 };

 class priorityQueue
 {
 public:

	 struct node
	 {
		 int val;
		 int priority;

		
		 node(int val, int priority):
			 val{ val }, priority{ priority } {}
	 };

	 vector <node> queue; 

	 void swap(node *x, node *y)
	 {
		 int tempVal = x->val;
		 int TempPrio = x->priority;

		 x->val = y->val;
		 x->priority = y->priority;

		 y->val = tempVal;
		 y->priority = TempPrio;
		 node* temp = y;
		 y = x;
		 x = temp;
	 }



	 void bubbleUp(int priority, vector<node>& arr)
	 {
		 if (arr.size() == 1)
		 {
			 return;
		 }

		 int currIdx = queue.size() - 1;
		 int currPro = arr[currIdx].priority;
		 int parentIdx = (currIdx - 1) / 2;
		 int parentPriority = queue[parentIdx].priority;
		
		 while (currPro < parentPriority)
		 {
			 if (currIdx == parentIdx  || currIdx == 0)
			 {
				 break;
			 }
			 node* parent = &arr[parentIdx];
			 node* curr = &arr[currIdx];
			 swap(curr, parent);
			 currIdx = parentIdx;
			 parentIdx = (currIdx - 1) / 2;
			 currPro = arr[currIdx].priority;
			 parentPriority = queue[parentIdx].priority;
		 }
	 }

	 void bubbleDown(int priority, vector<node>& arr)
	 {
		 int curr = 0; 
		 int child1 = (curr *2 ) + 1;
		 int child2 = (curr * 2) + 2;
		 int compare;

		 if (arr.size() == 1)
		 {
			 return;
		 }

		 else if (arr.size() == 2)
		 {
			 if (arr[0].priority > arr[1].priority)
			 {
				 node* first = &arr[0];
				 node* second = &arr[1];
				 swap(first, second);
				 return;
			 }
			 else
			 {
				 return;
			 }
		 }

		 for (;;)
		 {
			 if (arr[child1].priority < arr[child2].priority || arr[child1].priority == arr[child2].priority)
			 {
				 compare = child1;
			 }
			 else 
			 {
				 compare = child2;
			 }

			 if (arr[curr].priority > arr[compare].priority)
			 {
				 node* first = &arr[curr];
				 node* second = &arr[compare];
				 swap(first, second);
				 curr = compare; 
				 if ((curr *2 ) + 1 < (arr.size() - 1))
				 {
					 child1 = (curr * 2) + 1;
				 }
				 else
				 {
					 return;
				 }

				 if ((curr * 2) + 2 < (arr.size() - 1))
				 {
					 child2 = (curr * 2) + 2;
				 }
				 else
				 {
					 if (arr[curr].priority > arr[child1].priority)
					 {
						 node* first = &arr[curr];
						 node* second = &arr[child1];
						 swap(first, second);
						 return;
					 }
				 }
			 }
			 else
			 {
				 return;
			 }
		 }
	 }

	 void enqueue(int val, int priority)
	 {
		 node* temp = new node(val, priority);
		 queue.push_back(*temp);
		 bubbleUp(temp->priority, queue);
		 
	 }

	 node dequeue()
	 {
		 if (queue.size() == 1)
		 {
			 node* del = &queue.front();
			 queue.erase(queue.begin() + (queue.size() - 1));
			 return *del;
		 }
		 node* first = &queue.front();
		 node* last = &queue.back();
		 swap(first,last);
		 queue.erase(queue.begin() + (queue.size() - 1));
		 bubbleDown(first->priority, queue);
		 return *last;
	 }

 };

 class hashMap
 {
	 list<pair<string,string>> items[3];
	 
 int hashme(string key)
 {
	 int curr;
	 int total = 0;
	 int prime = 99;
	 for (int i = 0; i < key.size(); i++)
	 {
		 curr = key[i];
		 total = (total * prime + curr) % 3;
	 }
	 return total;
 }

 public:
 void set(string key, string value)
 {
	 int index = hashme(key);
	 items[index].push_back(make_pair(key,value));
 }

 string get(string key)
 {
	 int index = hashme(key);
	 list <pair<string,string>> ::iterator it;
	 for (it = items[index].begin(); it != items[index].end(); ++it)
	 {
		 if (it->first == key)
		 {
			 return it->second;
		 }
	 }
	 cout << "not found!" << endl;
	 return "";
 }
 
 vector<string> keys()
 {
	 vector<string> res;
	 if (res.size() == 0)
	 {
		 res.push_back(items[0].begin()->first);
	 }

	 for (int i = 0; i < 3; i++)
	 {
		 if (items[i].size() != 0)
		 {
			 list <pair<string, string>> ::iterator it;
			 for (it = items[i].begin(); it != items[i].end(); ++it)
			 {
				 string val = it->first;
				 if (res.size() != 0)
				 {
					 bool found = false;
					 for (int j = 0; j < res.size(); j++)
					 {
						 if (val == res[j])
						 {
							 found = true;
							 break;
						 }
					 }
					 if (found == false)
					 {
						 res.push_back(val);
					 }

				 }
			 }

		 }
	 }
	 return res;
 }
  
 vector<string> values()
 {
	 vector<string> res;
	 if (res.size() == 0)
	 {
		 res.push_back(items[0].begin()->second);
	 }

	 for (int i = 0; i < 3; i++)
	 {
		 if (items[i].size() != 0)
		 {
			 list <pair<string, string>> ::iterator it;
			 for (it = items[i].begin(); it != items[i].end(); ++it)
			 {
				 string val = it->second;
				 if (res.size() != 0)
				 {
					 bool found = false;
					 for (int j = 0; j < res.size(); j++)
					 {
						 if (val == res[j])
						 {
							 found = true;
							 break;
						 }
					 }
					 if (found == false)
					 {
						 res.push_back(val);
					 }

				 }
			 }

		 }
	 }
	 return res;
 }
 };

 class graph
 {
 public:
	 struct edge
	 {
		 int val, weight;

		 edge(int val, int weight)
			 :val{ val }, weight{ weight } {}
	 };
	 map<int, vector<edge>> elements;
	 void addVertex(int val)
	 {
		 elements.insert(make_pair(val, vector <edge>{}));
	 }
	 void addEdge(int vertex1, int vertex2 , int weight)
	 {
		 edge* Edge1= new edge(vertex1,weight);
		 edge* Edge2= new edge(vertex2,weight);

		 elements[vertex1].push_back(*Edge2);
		 elements[vertex2].push_back(*Edge1);
	 }
	 void removeVertex(int val)
	 {
		 
		 for (int i = 0; i < elements[val].size(); i++)
		 {
			 int key = elements[val][i].val;
			 for (int j = 0; j < elements[key].size(); j++)
			 {
				 if (elements[key][j].val == val)
				 {
					 elements[key].erase(elements[key].begin() + j);
				 }
			 }
			 
		 }
		 elements.erase(val);
	 }
	 void removeVertex2(int val)
	 {
		 for (int i = elements[val].size() - 1; i >=0 ; i--)
		 {
			 int key = elements[val][i].val;
			 removeEdge(val, key);
		 }
		 elements.erase(val);
	 }
	 void removeEdge(int vertex1, int vertex2)
	 {
		 for (int i = 0; i < elements[vertex1].size(); i++)
		 {	
			 if (elements[vertex1][i].val == vertex2)
			 {
				 elements[vertex1].erase(elements[vertex1].begin() + i);
			 }
		 }

		 for (int i = 0; i < elements[vertex2].size(); i++)
		 {
			 if (elements[vertex2][i].val == vertex1)
			 {
				 elements[vertex2].erase(elements[vertex2].begin() + i);
			 }
		 }
	 }
	 unordered_map<int,bool> traversed;
	 unordered_map<int, vector<edge>> result; 
	 void recursiveCall(int val)
	 {
		 if (traversed[val] != true)
		 {
			 result[val] = elements[val];
		 }
		 else return;
		 traversed[val] = true;
		 for (auto el : elements[val])
		 {
			 recursiveCall(el.val);
		 }
	 }
	 void recursiveDFS()
	 {
		 int root = 1;
		 recursiveCall(root);
	 }
	 void iterativeDFS()
	 {
		 map<int, vector<edge>>::iterator it;
		 for (it = elements.begin(); it != elements.end(); it++)
		 {
			 if (traversed[it->first] != true)
			 {
				 result[it->first] = it->second;
				 traversed[it->first] = true;
			 }
		 }
	 }
	 void iterativeDFS2(int start)
	 {
		 stack<pair<int, vector<edge>>> s;
		 s.push(make_pair(start, elements[start]));
		 while (s.size() != 0)
		 {
			 pair<int, vector<edge>> vertex = s.top();
			 s.pop();
			 if (traversed[vertex.first] != true)
			 {
				result.insert(vertex);
				traversed[vertex.first] = true;
				for (auto el : elements[vertex.first])
				{
					s.push(make_pair(el.val, elements[el.val]));
				}
			 }
		 }
	 }
	 void bfs(int root)
	 {
		 queue<pair<int, vector<edge>>> q;
		 q.push(make_pair(root,elements[root]));

		 while (q.size() != 0)
		 {
			 pair<int, vector<edge>> vertex = q.front();
			 q.pop();
			 if (traversed[vertex.first] != true)
			 {
				 result.insert(vertex);
				 traversed[vertex.first] = true;
				 for (auto el : elements[vertex.first])
				 {
					 q.push(make_pair(el.val, elements[el.val]));
				 }
			 }
		 }
	 }
	 void bfs2(int root) // more optimized
	 {
		 queue<pair<int, vector<edge>>> q;
		 q.push(make_pair(root, elements[root]));
		 pair<int, vector<edge>> vertex;

		 while (q.size() != 0)
		 {
			 vertex = q.front();
			 result.insert(vertex);
			 q.pop();

			 for (auto el : elements[vertex.first])
			 {
				 if (traversed[el.val] != true)
				 {
					 traversed[el.val] = true;
					 q.push(make_pair(el.val, elements[el.val]));
				 }
			 }
		 }
	 }
 };

 class lin
 {
 public: 
	 struct node
	 {
		 int val; 
		 node* next; 

		 node(int val, node* next)
			 : val{ val }, next{ next } {}

		 node(int val)
			 : val{ val }, next{ NULL } {}
	 };

	 node* head = NULL; 
	 node* tail = NULL;

	 void unshift(int  val)
	 {
		 node* temp = new node(val, head);
		 if (head == NULL)
		 {
			 head = temp;
			 tail = temp;
		 }

		 else
		 {
			 head = temp;
		 }
	 }
	 void push(int val)
	 {
		 node* temp = new node(val);

		 if (head == NULL)
		 {
			 head = temp; 
			 tail = temp; 
		 }

		 else
		 {
			 tail->next = temp; 
			 tail = temp;
		 }
	 }
	 void place(int val, int place)
	 {
		 if (place == head->val)
		 {
			 node* temp = new node(val, head->next);
			 head->next = temp;
			 return;
		 }
		 else if (place == tail->val)
		 {
			 push(val);
			 return;
		 }
		 node* curr = head;
		 while (curr->next->val != place )
		 {
			 if (curr->next->next == NULL)
			 {
				 return;
			 }
			 curr = curr->next;
		 }
		 node* temp = new node(val, curr->next->next);
		 curr->next->next = temp;
	 }
	 
	 node get(int val)
	 {
		 node *curr = head; 
		 while (curr->val != val)
		 {
			 if (curr->next == NULL && curr->val != val)
			 {
				 return NULL;
			 }
			 curr = curr->next;
		 }
		 return *curr; 
	 }
	 void set(int place , int val)
	 {
		 node* curr = head; 
		 while (curr->val != place)
		 {
			 if (curr->next == NULL && curr->val != place)
			 {
				 return; 
			 }
			 curr = curr->next;
		 }
		 curr->val = val; 
	 }

	 void shift()
	 {
		 node* del = head; 
		 head = head->next; 
		 delete del;
	 }
	 void pop()
	 {
		 node* curr = head;
		 while (curr->next->next != NULL)
		 {
			 curr = curr->next; 
		 }
		 node* del = tail; 
		 tail = curr; 
		 delete del; 
	 }
	 void deleteVal(int val)
	 {
		 if (val == head->val)
		 {
			 shift();
			 return;
		 }
		 else if (val == tail->val)
		 {
			 pop();
		 }
		 node* curr = head; 
		 while (curr->next->val != val)
		 {
			 if (curr->next->next == NULL && curr->next->val != val)
			 {
				 return;
			 }
			 curr = curr->next;
		 }
		 node* temp = curr->next->next;
		 delete curr->next;
		 curr->next = temp;
	 }

	 void reverse()
	 {
		 node* prev = NULL; 
		 node* next = head->next; 
		 node* curr = head;
		 while (next != NULL)
		 {
			 curr->next = prev; 
			 prev = curr;
			 curr = next;
			 next= next->next;
		 }
		 tail->next = prev;
		 node* temp = head; 
		 head = tail; 
		 tail = temp;

	 }
 };

 void dijkstra(graph gr, pair<int, vector<graph::edge>> source)
 {
	 set<pair<int,int>> queu; // (distance, value)
	 unordered_map <int, int> distance; // key: distance
	 unordered_map <int, int> previous; // key: previous
	 unordered_map <int, bool> visited; // key: visited

	 for (auto el : gr.elements)
	 {
		 if (el.first == source.first)
		 {
			 distance.insert(make_pair(el.first, 0));
			 previous.insert(make_pair(el.first, NULL));
			 visited.insert(make_pair(el.first, false));
		 }
		 else
		 {
			 distance.insert(make_pair(el.first,999999));
			 previous.insert(make_pair(el.first, NULL));
			 visited.insert(make_pair(el.first, false));
		 }
	 }
	 queu.insert(make_pair(distance[source.first], source.first));

	 while (!queu.empty())
	 {
		 vector<graph::edge>  curr = gr.elements[queu.begin()->second];
		 int currVal = queu.begin()->second;
		 visited[currVal] = true;
		 queu.erase(queu.begin());
		 for (auto el : curr)
		 {
			 
			 if (visited[el.val] != true)
			 {
				 if (el.weight + distance[currVal] < distance[el.val])
				 {
					 distance[el.val] = el.weight + distance[currVal];
					 previous[el.val] = currVal;
					 queu.insert(make_pair(distance[el.val], el.val));
				 }
			 }
				 
		 }
	 }
 }


 int fib(int number, int fibo[])
 {
	 if (fibo[number] != -1)
	 {
		 return fibo[number];
	 }

	 if (number <= 2)
	 {
		 return 1;
	 }

	 else 
	 {
		 int res = fib(number - 1, fibo) + fib(number - 2, fibo);
		 fibo[number] = res;
		 return res;
	 }

 }

 int main()
 {
	 vector <int> arr1 = {1,5,62,56,23,33,12,355,2};
	 //vector <pair<int, int>> res = mult_pt(arr1, 4);

	 //for (int j = 0; j < res.size(); j++)
	 //{
		// cout << "[ " << res[j].first << " , " << res[j].second << " ]" << endl;
	 //}

	 //cout << endl;

	 for (int i = 0; i < arr1.size(); i++)
	 {
		 cout << arr1[i] << endl;
	 }
	 cout << endl;
	 cout << endl;	 

	 //int res = hashme("hit",5);
	 //cout << res;
	 //res = hashme("ping",5);
	 //cout << res;
	 //res = hashme("pink",5);
	 //cout << res;
	 //res = hashme("byte",5);
	 //cout << res;
	 //res = hashme("bits",5);
	 //cout << res;
	 
	 //hashMap ha; 
	 //ha.set("N","Nibba");
	 //ha.set("T","Trouser");
	 //ha.set("C","Cake");
	 //ha.set("B","Book");
	 //ha.set("o","Book");
	 //ha.set("i","Book");
	 //ha.set("u","Book");
	 //ha.set("y","Book");
	 //ha.set("r","Book");
	 //ha.set("e","Book");
	 //ha.set("w","Book");
	 //ha.set("q","Book");

	 //string res = ha.get("B");


	 //vector <string> res3= ha.keys();
	 //vector <string> res2 = ha.values();

	 //graph gr; 
	 //gr.addVertex(1);
	 //gr.addVertex(2);
	 //gr.addVertex(3);
	 //gr.addVertex(4);
	 //gr.addVertex(5);
	 //gr.addEdge(1,2,8);
	 //gr.addEdge(1,4,12);
	 //gr.addEdge(1,5,13);
	 //gr.addEdge(2,3,1);
	 //gr.addEdge(4,3,1);
	 //gr.addEdge(5,4,1);
	 //gr.bfs2(1);
	 //dijkstra(gr, *gr.elements.begin());

	 //lin li; 
	 //li.push(1); 
	 //li.push(2); 
	 //li.push(3); 
	 //li.push(4); 
	 //li.push(5); 
	 //li.push(6); 
	 //lin::node res= li.get(5);
	 //li.reverse();
	 int fibo[10];
	 fill_n(fibo,10,-1);
	 for (auto el : fibo)
	 {
		 cout << el;
	 }
	 int res = fib(7, fibo);
	 cout << endl;
	 cout << endl;

	 system("pause");
 }