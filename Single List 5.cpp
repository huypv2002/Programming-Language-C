/*Bài này bao gồm các hàm sắp xếp danh sách, sử dụng các thuật toán sau :
- Interchange Sort    O(n^2)
- Buble Sort          O(n^2)
- Selection Sort      O(n^2)
- Insertion Sort      O(n^2) hoặc O(n)
*/

/*Nếu bạn sắp xếp tăng dần, chỉ cần gọi :           list.sort_interchange();
Nếu là sắp xếp giảm dần, phải thêm tham số false :  list.sort_interchange(false);
*/

//Sắp xếp danh sách dùng Interchange Sort
template <class data>
void SList<data>::sort_interchange(bool ascending)
{
  if(len <= 1)
    return;
  
  if(ascending)   //Sắp xếp danh sách tăng
  {
    for(node<data>* i = head; i; i = i->next)
      for(node<data>* j = i->next; j; j = j->next)
        if(i->info > j->info)
          swap(i->info, j->info);
  }else{
    for(node<data>* i = head; i; i = i->next)
      for(node<data>* j = i->next; j; j = j->next)
        if(i->info < j->info)
          swap(i->info, j->info);
  }
}

//Sắp xếp danh sách dùng Buble Sort
template <class data>
void SList<data>::sort_buble(bool ascending)
{
  if(len <= 1)
    return;
  
  node<data>* p = NULL;
  
  if (ascending)   //Sắp xếp danh sách tăng
  {
    for (node<data>* i = head; i->next != p;)
      for (node<data>* j = i;; j = j->next)
      {
        if (j->next == p)
        {
          p = j;
          break;
        }

        if (j->info > j->next->info)
          swap(j->info, j->next->info);
      }
  }else{
    for (node<data>* i = head; i->next != p;)
      for (node<data>* j = i;; j = j->next)
      {
        if (j->next == p)
        {
          p = j;
          break;
        }

        if (j->info < j->next->info)
          swap(j->info, j->next->info);
      }
  }
}

//Sắp xếp danh sách dùng Selection Sort
template <class data>
void SList<data>::sort_selection(bool ascending)
{
  if(len <= 1)
    return;
  
  node<data>* p;
  
  if(ascending)   //Sắp xếp danh sách tăng
  {
    for(node<data>* i = head; i; i = i->next)
    {
      p = i;
      for(node<data>* j = i->next; j; j = j->next)
        if(p->info > j->info)
          p = j;
      
      if(p != i)
        swap(p->info, i->info);
    }
  }else{
    for(node<data>* i = head; i; i = i->next)
    {
      p = i;
      for(node<data>* j = i->next; j; j = j->next)
        if(p->info < j->info)
          p = j;
      
      if(p != i)
        swap(p->info, i->info);
    }
  }
}

/*Vì danh sách liên kết đơn chỉ có thể duyệt theo chiều xuôi, nên ta sẽ xử dụng kỹ thuật đệ quy cho bài toán Insertion Sort
Hàm này không phải là lớp của SList
*/

template <class data>
void SList_insertion(node<data>* head, bool ascending)    //Nhận vào một nút
{
  if(head == NULL || head->next == NULL)
    return;
    
  SList_insertion(head->next, ascending);     //Đệ quy
  
  data temp = head->info;       //Giữ giá trị nút đang xét
  node<data>* i = head;
  
  //Phần sắp xếp chèn
  if(ascending)   //Sắp xếp danh sách tăng
  {
    for(; i->next && i->next->info < temp; i = i->next)
      i->info = i->next->info;
    i->info = temp;
  }else{
    for(; i->next && i->next->info > temp; i = i->next)
      i->info = i->next->info;
    i->info = temp;
  }
}

//Sắp xếp danh sách dùng Insertion Sort
template <class data>
void SList<data>::sort_insertion(bool ascending)
{
  if(len <= 1)
    return;
  
  SList_insertion(head, ascending);
}
//bull neeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
