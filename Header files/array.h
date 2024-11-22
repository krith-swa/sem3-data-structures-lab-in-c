//ADT structure
#define MAX_SIZE 15
#define DELIM -999

int size (int A[]) {
	int count;
	for (count=0; A[count]!=DELIM; count++);
	return count;
	}

int insertAt (int A[], int size, int pos, int data) {
	if (pos>=0 && pos<=size) {
    		A[size+1]=DELIM;
		for (int i=size; i>pos; i--)
			A[i]=A[i-1];
		A[pos]=data;
		return size+1;
		}
	else if (pos<0)
		return -2;
	else if (pos>size)
		return -3;
	else
		return -1;
	}

int search (int A[], int pos, int key) {
	if (pos>=0 && pos<size(A)) {
		for (int i=pos; A[i]!=DELIM; i++) {
      			if (A[i]==key)
       	 			return i;
      			}
		return -1;
    		}
	else if (pos<0)
  		return -2;
	else if (pos>=size(A))
		return -3;
	}

