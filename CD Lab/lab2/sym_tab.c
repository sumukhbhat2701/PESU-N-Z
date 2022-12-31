#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_tab.h"

table* allocate_space_for_table()	
{
    	table* T = (table*)malloc(sizeof(table));
	T->head = NULL;
	return T;
}

symbol* allocate_space_for_table_entry(char* name, int size, int type, int lineno, int scope) 
{
    	symbol* new_ = (symbol*)malloc(sizeof(symbol));
    	new_->name = (char*)malloc(strlen(name)+1);
	strcpy(new_->name, name);
	new_->size = size;
	new_->type = type;
	new_->line = lineno;
	new_->scope = scope;
	new_->val = (char*)malloc(4);
	strcpy(new_->val, "---");
	return new_;
}

void insert_into_table(char* name, int size, int type, int lineno, int scope)
{
    if(t->head == NULL)
    	t->head = allocate_space_for_table_entry(name, size, type, lineno, scope);
    else
    {
    	symbol* ptr = t->head;
    	while(ptr->next!=NULL)
    		ptr = ptr->next;
    	ptr->next = allocate_space_for_table_entry(name, size, type, lineno, scope);
    	
    }

}

int check_symbol_table(char* name) //return a value like integer for checking
{
    if(t->head == NULL) return 0;
    symbol* ptr = t->head;
    while(ptr!=NULL)
    {
    	if(strcmp(ptr->name, name) == 0) return 1;
    	ptr = ptr->next;
    }
    return 0;
}

void insert_value_to_name(char* name, char* value)
{
    if(!strcmp(value, "---"))
    	return;
    if(t->head == NULL)
    	return;
    else
    {
    	symbol* ptr = t->head;
    	while(ptr!=NULL)
    	{
    		if(!strcmp(name, ptr->name))
    		{
    			ptr->val = (char *)realloc(ptr->val, strlen(value)+1);
    			strcpy(ptr->val, value);
    		}
    		
    		ptr = ptr->next;
    	}

    }
    
}

void display_symbol_table()
{

    symbol* ptr = t->head;
    printf("Name\tSize\tType\tLineNum\tScope\tValue\n");
    while(ptr!=NULL)
    {
    	printf("%s\t%d\t%d\t%d\t%d\t%s\n", ptr->name, ptr->size, ptr->type, ptr->line, ptr->scope, ptr->val);
    	ptr = ptr->next;
    }
}
