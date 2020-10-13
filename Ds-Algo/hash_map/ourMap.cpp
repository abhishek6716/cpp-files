#include<iostream>
#include<string>
using namespace std;

template<typename v>
class mapNode{
    public:
    string key;
    v value;
    mapNode* next;

    mapNode(string key, v value){
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~mapNode(){
        delete next;
    }
};

template<typename v>
class ourmap{
    mapNode<v>** buckets;
    int count;
    int numBuckets;

    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets=new mapNode<v>*[numBuckets];
        for(int i=0; i<numBuckets; i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0; i<numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

    v getValue(string key){
        int bucketIndex=getBucketIndex(key);
        mapNode<v>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }

    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int currCoeff=1;
        for(int i=key.length()-1; i>=0; i--){
            hashCode=hashCode+key[i]*currCoeff;
            hashCode=hashCode%numBuckets;
            currCoeff=currCoeff*37;
            currCoeff=currCoeff%numBuckets;
        }
        return hashCode%numBuckets;
    }

    void rehash(){
        mapNode<v>** temp=buckets;
        buckets=new mapNode<v>*[2*numBuckets];
        for(int i=0; i<2*numBuckets; i++){
            buckets[i]=NULL;
        }
        int oldBucketCount=numBuckets;
        numBuckets=numBuckets*2;
        count=0;
        
        for(int i=0; i<oldBucketCount; i++){
            mapNode<v>* head=temp[i];
            while(head!=NULL){
                string key=head->key;
                v value=head->value;
                insert(key, value);
                head=head->next;
            }
        }

        for(int i=0; i<oldBucketCount; i++){
            mapNode<v>* head=temp[i];
            delete head;
        }
        delete []temp;
    }
    public:
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    void insert(string key, v value){
        int bucketIndex=getBucketIndex(key);
        mapNode<v>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        mapNode<v>* newNode=new mapNode<v>(key, value);
        newNode->next=head;
        buckets[bucketIndex]=newNode;
        count++;
        double loadFactor=(1.0*count)/numBuckets;
        if(loadFactor>0.7){
            rehash();
        }
    }

    v remove(string key){
        int bucketIndex=getBucketIndex(key);
        mapNode<v>* head=buckets[bucketIndex];
        mapNode<v>* prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;
                }
                else{
                    prev->next=head->next;
                }
                v value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};

int main(){
    ourmap<int> map;
    for(int i=0; i<10; i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key, value);
        cout<<map.getLoadFactor()<<endl;
    }

    cout<<map.size()<<endl;

    map.remove("abc2");
    map.remove("abc7");

    cout<<map.size()<<endl;

    for(int i=0; i<10; i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":"<<map.getValue(key)<<endl;
    }

    cout<<map.size()<<endl;
}