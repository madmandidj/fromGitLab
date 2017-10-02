template <typename dlistType>
class LList 
{
	class Node;
	
	public:
		class Iterator
		{
			public:
			Iterator();
//			~Iterator();
			dlistType get() const;
			void next();
			void previous();
			bool equals(Iterator iter) const;
			
//			private:
			Node* position;
			LList* container;
		};

		LList();
		~LList();
		void pushBack(dlistType data);
		Iterator begin();
		Iterator end();
		void insert (Iterator iter, dlistType data);
		Iterator erase(Iterator Iter);
		
	private:
	class Node
	{
		public:
		Node(dlistType data);
//		private:
//		protected:
		dlistType data;
		Node* ptr_next;
		Node* ptr_prev;
	};
	Node* ptr_first;
	Node* ptr_last;
};








template <typename dlistType> 
LList<dlistType>::Node::Node(dlistType data)
{
     this->data = data;
     ptr_next = 0;
     ptr_prev =0;
}

template <typename dlistType> 
LList<dlistType>::Iterator::Iterator()
{
    position = 0;
    container = 0;
}

template <typename dlistType> 
dlistType LList<dlistType>::Iterator::get() const
{
    return position->data;
}

template <typename dlistType> 
void LList<dlistType>::Iterator::next()
{
    if(position == container->ptr_last)
    {
                position = container->ptr_first;
    }
    else
    {
                position = position->ptr_next;
    }
}

template <typename dlistType> 
void LList<dlistType>::Iterator::previous()
{
 if(!position)
 {                  
                    position = container->ptr_last;
 }
 else
 {
     position = position->ptr_prev;
 }
}

template <typename dlistType> 
bool LList<dlistType>::Iterator::equals(Iterator iter) const
{
 return position == iter.position;
}

template <typename dlistType>      
LList<dlistType>::LList()
{
  ptr_first = 0;
  ptr_last = 0;
}

template <typename dlistType> 
LList<dlistType>::~LList()
{
  while (ptr_first)
  {
        Node* tmp = ptr_first;
        ptr_first = ptr_first->ptr_next;
        delete tmp;
        tmp = 0;
  }
}

template <typename dlistType> 
void LList<dlistType>::pushBack(dlistType data)
{
	Node* new_node = new Node(data); 
	if(ptr_first==0)
	{
		ptr_first = new_node;
		ptr_last = new_node;
	}
	else
	{
		ptr_last->ptr_next = new_node;
		new_node->ptr_prev = ptr_last;
		ptr_last = new_node;
	}
}          

 template <typename dlistType> 
 typename LList<dlistType>::Iterator LList<dlistType>::begin()
 {
     Iterator iter;
     iter.position = ptr_first;
     iter.container = this;
     return iter;
  }

template <typename dlistType> 
 typename LList<dlistType>::Iterator LList<dlistType>::end()
{
     Iterator iter;
     iter.position = ptr_last;
     iter.container = this;
     return iter;
 }

 template <typename dlistType> 
 void LList<dlistType>::insert(Iterator iter, dlistType data)
 {
     if (iter.position == 0)
     {
         pushBack(data);
         return;
     }
     Node* before;
     Node* after;
     after = iter.position;
     before = iter.position->ptr_prev;
     Node* new_node = new Node(data);

     after->ptr_prev = new_node;
     if (before == 0) ptr_first = new_node;
     else before->ptr_next = new_node;

     new_node->ptr_prev = before;
     new_node->ptr_next = after;
  }                             

  template <typename dlistType> 
  typename LList<dlistType>::Iterator LList<dlistType>::erase(Iterator iter)
  {
     Node* after = iter.position->ptr_next;
     Node* before = iter.position->ptr_prev;
     Node* remove = iter.position;
     if (remove == ptr_first) ptr_first = after;
     else before->ptr_next = after;
     if (remove == ptr_last) ptr_last = before;
     else after->ptr_prev = before;
     delete remove;
     remove = 0;
   }
