    #include <iostream>

    /**
     * @brief Disfunctiional but though i'd show it still
     * @brief i forgot about dynamic allocation "new"
     * @bug Stackoverflow - cnewArray inside a loop on the limited stack.
     * @bug Bufferoverflow -Copying a large array (newArray) into a small, fixed-size array (arrArr)
     */

    int doubleIt(int size);
    void printArray(int* array, int size);

    int main()
    {

        int value;
        std::cout << "How big is the array";

        std::cin >> value;

        int oldSize = value;
        int newSize = value;
        int arrArr[value];
        // The main array is created on the stack with a FIXED size.
        // This is the root cause of the buffer overflow.

        // i needed to use the new keyword

        for (int i = 0; i < newSize; i++)
        {
            std:: cout<< "element [" << i << "]: ";
            std:: cin >> arrArr[i];
        }

        bool yes = true;
        char yarn = 'y';

        while (yes)
        {
            int newArray[newSize]; // creates a virtual array that only exist on the while loop
            // intuition: if we override the newarray then we wont have to worry about sizing
            // error: what is the error 
            
            std::cout << "memory full what should you do now, y for more n to exit and display";
            std::cin >> yarn;   
            if (yarn != 'y')
            {
                printArray(newArray, newSize);
                break;
            }
                        
            newSize = doubleIt(newSize);
            

            for (int i = 0; i < oldSize; i++)
            {
                newArray[i] = arrArr[i]; // gets a whole copy from arrArr 
            }

        
            for (int i = oldSize; i < newSize; i++)
            {
                std::cout << "element[" << i << "]:";
                std::cin >> newArray[i];  
            }

            for (int i = 0; i < newSize; i++)
            {
                arrArr[i] = newArray[i];  
            }

            
            oldSize = newSize;

        }

        return 0;



    }

    // @brief returns the double size of an array
    int doubleIt(int size)
    {
        return size * 2;
    }

    /**
     * @brief prints the array
     */
    void printArray(int* array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i];
        }
    }

    


    //footnote segmentation fault was cause by accidentally doing i <= size on a earlier iteration