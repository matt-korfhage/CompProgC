/*
 * Even-Up Solitaire O(n) solution for n integers.
 * MSOE Competitive Programming Week 6
 * Author: Matthew Korfhage
 * Language: C++ 17
 * Date: 1/17/2023
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE (100000*2)
#define DECIMAL_RADIX 10

namespace EvenUpSolitaire {
    class LinkedList {
        public:
            class Node {
                public:
                    Node *next = nullptr;
                    Node *prev = nullptr;
                    int data;

                explicit Node(int data) {
                    this->data = data;
                }
            };

            Node *head = nullptr;
            Node *tail = nullptr;
            int size = 0;

            void push(int data) {
                Node *n = new Node(data);
                if (size++ <= 0) {
                    head = n;
                    tail = n;
                } else {
                    tail -> next =  n;
                    n -> prev = tail;
                    tail = n;
                }
            }
    };

    int EvenUpSolitaire() {
        // get initial input value & set integer buffer
        char buffer[MAX_INPUT_SIZE];
        fgets(buffer, MAX_INPUT_SIZE-1, stdin);
        int n = (int) strtol(strtok(buffer, ""), nullptr, DECIMAL_RADIX);
        fgets(buffer, MAX_INPUT_SIZE-1, stdin);
        // receive solitaire values
        LinkedList list = LinkedList();

        /* don't worry about any of this stuff in this loop, just C++ shenanigans to
         interpret the input from the console and populate linked list */
        for(int i = 0; i < n; ++i) {
            volatile char *tok;
            if(i == 0) {
                tok = strtok(buffer, " ");
            } else {
                tok = strtok(nullptr, " ");
            }
            list.push((int) strtol((const char *)tok, nullptr, 10));
        }

        LinkedList::Node *current = list.head;
        while(true) {
            if(current->next == nullptr) {
                break;
            }
            if((current->data + current->next->data) % 2 == 0) {
                if(current == list.head) {
                    list.head = current->next->next;
                    current = list.head;
                }
                else {
                    current->prev->next = current->next->next;
                    current = current->prev;
                }
                list.size -= 2;
            }
            else {
                current = current->next;
            }
        }

        printf("%d", list.size);
        return 0;
    }
}