void levelorder (ptnodeInt root) {
	btQueueInt_ptr levelQueue = createBTIntQueue(SIZE);
	ptnodeInt EOL = insertNodeChar('|');
	ptnodeInt EOB = insertNodeChar(';');
	ptnodeInt blank = insertNodeChar('_');
	int ht = height(root);
	
	enqueueIntBT(levelQueue,EOL);
	int level = 1, k=0, eob=0;
	for (int i=0; i<=(ht-level); i++)
		printf("\t");
	while (root) {
		if (root!=blank && root!=EOB) {
			if ( root->item == '$' )
				printf("%d ",root->data);
			else if (isOperator(root->item))
				printf("%c ",root->item);
			if (root->left)
				enqueueIntBT(levelQueue,root->left);
			else
				enqueueIntBT(levelQueue,blank);
			if (root->right)
				enqueueIntBT(levelQueue,root->right);
			else
				enqueueIntBT(levelQueue,blank);
			enqueueIntBT(levelQueue,EOB);
			root = dequeueIntBT(levelQueue);
			}
			
		while (root == blank) {
			root = dequeueIntBT(levelQueue);
			printf("\t");
			k++;
			}
		while (root == EOB) {
			root = dequeueIntBT(levelQueue);
			if (root != EOL) {
				printf("  ");
				eob++;
				}
			}
		if (root == EOL) {
			root = dequeueIntBT(levelQueue);
			if (root != NULL) {
				enqueueIntBT(levelQueue,EOL);
				level++;
				printf("\n\n");
				for (int i=0; i<=(ht-level); i++)
					printf("\t");
				for (int i=0; i<k; i++)
					printf("\t");
				for (int i=0; i<eob; i++)
					printf("   ");
				}
			}
		}
	printf("\n");
	}
