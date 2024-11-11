#include<bits/stdc++.h>
using namespace std;
 
      class Node{
        public:
           int val;
            Node *next;
              Node(int val){
                  this->val =  val;
                    this->next = NULL;
              }
      };
         class myStack{
                public:
                  Node *head = NULL;
                   Node *tail = NULL;
                   void push(int val){
                      Node *newNode  = new Node(val);
                       if(head == NULL){
                         head =  newNode;
                          tail =  newNode;
                          return;
                       };
                        tail->next = newNode;
                        tail = newNode;
                        // Node *tmp = head;
                        //   while (tmp->next != NULL)
                        //   {
                        //       tmp = tmp->next;
                        //   };
                        //    tmp->next= newNode; 
                   };
                    
                    void pop(){
                            if(head == NULL) return;
                          if(head->next == NULL){
                               Node *deleteNode =  head;
                                head = head->next;
                                 delete deleteNode;
                          };
                            Node *tmp =  head;
                               while (tmp->next->next != NULL)
                               {
                                    tmp = tmp->next;
                               };
                                   delete tmp->next;
                                    tmp->next =  NULL;
                    };
                      
   

                     
                     int size(){
                         int count = 0;
                           Node *tmp = head;
                            while (tmp!= NULL)
                            {  
                                   count++;
                                    tmp = tmp->next;
                            };
                             return count;
                     };

                    int top(){
                           if(head->next == NULL){
                             return head->val;
                           };
                            Node *tmp = head;
                             while (tmp->next != NULL)
                             {
                                 tmp =  tmp->next;
                             };
                              return tmp->val; 
                      };
                       
                      bool empty(){
                        if(size() == 0 ) return true;
                         else  return false;
                      };
         };
        
            // bool  isEquele(myStack& st,myStack1 &st2){
            //     if(st.size() != st2.size()){
            //          return false;
            //     };
            //       while (!st.empty() && !st2.empty())
            //       {
            //           if(st.top() != st2.top()){
            //                return false;
            //           };
            //              st.pop();
            //               st2.pop();
            //       };
            //       return true;
            // };

            bool compareStacks(myStack& st1, myStack& st2) {
    if (st1.size() != st2.size()) {
        return false;
    }
    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            return false;
        }
        st1.pop();
        st2.pop();
    }
    return true;
}
           
 int main(){
         myStack st;
         myStack st2;

          int n; cin>>n;
            for(int i = 0; i<n;i++){
                 int val;cin>>val; st.push(val);
            };

               int x; cin>>x;
            for(int i = 0; i<x;i++){
                 int val;cin>>val; st2.push(val);
            };
     

               if(compareStacks(st,st2)){
                    cout<<"YES"<<endl;
               }else{
                     cout<<"NO"<<endl;
               };


            //  while (st.empty() ==  false)
            //  {
            //          cout<<st.top()<<" ";
            //           st.pop();
            //  };

     return 0;
 }