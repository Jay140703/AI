class Hashtable:
    def __init__(self):
        self.size = int(input("Enter the size of the hash table: "))
        self.count = 0
        self.list = [None] * self.size
        self.comparisons = 0

    def hashfunction(self, key):
        return key % self.size

    def is_full(self):
        return self.count == self.size

    def insert(self, key):
        if not isinstance(key, int):
            return "Key must be an integer"
        if self.is_full():
            return "Hashtable is full"

        index = self.hashfunction(key)
        original_index = index

        while self.list[index] is not None:
            self.comparisons += 1
            if self.list[index] == key:
                return "Key already exists"
            index = (index + 1) % self.size
            if index == original_index:
                return "Hashtable is full"

        self.list[index] = key
        self.count += 1
        return "Key inserted successfully"

    def search(self, key):
        if not isinstance(key, int):
            return "Key must be an integer"
        index = self.hashfunction(key)
        original_index = index

        while self.list[index] is not None:
            self.comparisons += 1
            if self.list[index] == key:
                return f"Key found at index {index}"
            index = (index + 1) % self.size
            if index == original_index:
                break
        return "Key not found"

    def remove(self, key):
        if not isinstance(key, int):
            return "Key must be an integer"
        index = self.hashfunction(key)
        original_index = index

        while self.list[index] is not None:
            self.comparisons += 1
            if self.list[index] == key:
                self.list[index] = None
                self.count -= 1
                return f"Key {key} removed successfully"
            index = (index + 1) % self.size
            if index == original_index:
                break
        return "Key not found"

    def display(self):
        print("Hashtable contents:")
        for i in range(self.size):
            if self.list[i] is not None:
                print(f"Index {i}: {self.list[i]}")
            else:
                print(f"Index {i}: Empty")
        print(f"Total comparisons: {self.comparisons}")
        self.comparisons = 0


def menu():
    h1 = Hashtable()
    while True:
        print("\n--- Hashtable Operations ---")
        print("1. Insert a key")
        print("2. Search for a key")
        print("3. Remove a key")
        print("4. Display the hashtable")
        print("5. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            key = int(input("Enter the key to insert: "))
            print(h1.insert(key))
        elif choice == '2':
            key = int(input("Enter the key to search: "))
            print(h1.search(key))
        elif choice == '3':
            key = int(input("Enter the key to remove: "))
            print(h1.remove(key))
        elif choice == '4':
            h1.display()
        elif choice == '5':
            print("Exiting the program...")
            break
        else:
            print("Invalid choice. Please try again.")


# Start the program
menu()