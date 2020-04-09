	//4, 5
  	class List *new_list (T value) {
	    List *ls = new List;
	    bool f = true;
	    for (Item* t = first; t != nullptr; t = t->next)  {
	        if (f)
	            ls->add(t->inf);
	        if (t->inf==value) 
	            f = false;
	        else 
	            f = true;
	    };
	    return ls;
	}; 
	
	void list_remove(T value) {
	    Item* t;
	    int j=0;
	    for (t = first; t != nullptr; t = t->next) {
	        if (t->inf==value)
	            break;
	        j++;
	    };
	    for (int i=0; i<j; i++) {
	        Item *tmp = first;
	        first = first->next;
	        delete tmp;
	    };
	};
