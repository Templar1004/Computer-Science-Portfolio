# Computer-Science-Portfolio

Project Overview
Corner Grocer Item Tracker is a tool developed to provide the management of the store with useful and applicable information on the way the store’s customers shop. It identifies which produce products are performing well based on the transaction logs of the day, which helps the management to place the products appropriately in the store to increase sales. It is developed using the C++ programming language, focusing on modularity, data reliability, and user-friendliness.

Technical Highlights

Object-Oriented Foundation: Utilizes a dedicated ItemTracker class that takes care of the data processing and storing, which is well-organized.
Fast Data Access: Data is accessed (std::map<string, int>) using logarithmic time, and the data is also arranged alphabetically to make it easy to navigate through the inventory.
Reliable Persistence: On each run of the program, it creates a frequency.dat file to store the data long-term.
Visual Output: It has a feature that utilizes the iomanip library to provide the user with a visual representation of the purchase frequencies using a histogram.
Reflection
What I Did Well:
I'm pretty satisfied with the way I structured the data structure and got the program off the ground. The data structure that I ended up using was the std::map, as it meets the two requirements of keeping the items alphabetized while providing fast lookups and insertions, even as the inventory list grows. Additionally, the program is proactive, as it creates the backup file as soon as it is started.

Enhancement & Future Improvements
If I were to enhance this program, I would look more closely at the input validation, as security is an important part of any program, especially when it comes to the input file, as it could be corrupted or empty when the program is started. Additionally, the program could be more user-friendly by allowing the user to specify the file names by using a configuration file, as this would make the program more useful for different types of business environments.

Challenges & Overcoming Obstacles
The biggest challenge was the visual histogram that was required by the program. This was the hardest part, as the items need to be left-justified while the stars need to start at the same point as the items, so some trial and error was necessary with the iomanip library. The way that I was able to accomplish this was by referring to the C++ documentation for the iomanip library, as it explained the usage for the setw and left functions. The next resource that I would look at is the C++ reference, as found on cppreference.com, as it appears that this is the documentation for the C++ language, as well as documentation sites.

Free-style rewrite:

Transferable Skills
The main skill I can derive from this project is the ability to better comprehend the concept of Object-Oriented Programming (OOP). By bundling the code within the ItemTracker class, I was able to effectively separate the data and make it secure while also making the essential functions available. This skill can thus be transferred to my Java and Python programming.

Maintainability and Readability
I was also able to make the program maintainable by ensuring it was readable. I chose variable names that were descriptive and also added effective and well-thought-out comments to the code. I also made sure to separate the user interface code in the main() method and the data processing code within the class. This way, the code would remain effective even if the store decided to use a graphical interface instead of the text-based interface.

