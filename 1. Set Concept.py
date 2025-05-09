class MySet:
    def __init__(self, elements=None):
        if elements is None:
            self.set = []
        else:
            self.set = []
            for element in elements:
                if element not in self.set:
                    self.set.append(element)
    
    def union(self, set2):
        union_set = self.set.copy()
        for element in set2.set:
            if element not in union_set:
                union_set.append(element)
        return MySet(union_set)
    
    def intersection(self, set2):
        intersection_set = []
        for element in self.set:
            if element in set2.set:
                intersection_set.append(element)
        return MySet(intersection_set)
    
    def is_subset(self, set2):
        for element in self.set:
            if element not in set2.set:
                return False
        return True
    
    def difference(self, set2):
        difference_set = []
        for element in self.set:
            if element not in set2.set:
                difference_set.append(element)
        return MySet(difference_set)
    
    def display(self):
        print("Set:", self.set)

def input_set(prompt):
    user_input = input(prompt)
    elements = user_input.split(',')
    elements = [element.strip() for element in elements]
    return MySet([str(element) for element in elements])

def menu():
    print("\nMenu:")
    print("1. Union of sets")
    print("2. Intersection of sets")
    print("3. Check if set1 is a subset of set2")
    print("4. Difference of set1 and set2")
    print("5. Display sets")
    print("6. Exit")

def main():
    set1 = input_set("Enter the elements of set1 (comma separated): ")
    set2 = input_set("Enter the elements of set2 (comma separated): ")
    
    while True:
        menu()
        choice = int(input("Enter your choice: "))
       
        if choice == 1:
            result = set1.union(set2)
            print("Union of set1 and set2:", result.set)        
        elif choice == 2:
            result = set1.intersection(set2)
            print("Intersection of set1 and set2:", result.set)        
        elif choice == 3:
            if set1.is_subset(set2):
                print("Set1 is a subset of Set2.")
            else:
                print("Set1 is not a subset of Set2.")       
        elif choice == 4:
            result = set1.difference(set2)
            print("Difference of set1 and set2 (set1 - set2):", result.set)
        elif choice == 5:
            print("Set1:", set1.set)
            print("Set2:", set2.set)
        elif choice == 6:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()
