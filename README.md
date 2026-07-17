# *Task-manager*

### *Description*
This is a CLI task manager that can perform the following functions: add task (title, description, due date, completion status), view task list, update task list (and the categories of each task), clear task list. The program stores the tasks in a JSON file so the data is persistent!

This project is for HORIZONS EUROPA!!!

### *Purpose*
I want to learn (or relearn cause I know the basics) C++ by building mini projects, this is my first one. My goal was to recap basic syntax, loops, if statements, functions as well as learn how to handle files in C++. I just want to be familiar with C++ in general, cause its good for engineering and many hardware projets need it. Also learn how to use Github Codespaces. I used the code for a CLI task manager written by another person ThatBoiWitZM (GitHub username) in Python for inspiration. I already knew Python, so I thought it would be best to learn C++ by finding its equivalents to familiar structures in Python. 


### *Work process*
Writing the intial framework and basic logic of the program was easy, since I remembered most of it. However, when I got to the part where I had to introduce the JSON library it got very confusing. I am not very familiar with I/O streams, let alone JSON commands in C++. But with the power of online forums and a whole lot of debugging I understood and did it. Once I had the simplest version of the program down, I added complexity such as the option to update any of the task descriptors (title, description, date, status). Again, it was difficult, since I had to recalibrate some JSON commands. Then I had the bright idea of converting this logic to a website, but then I learnt that it would require rewritting almost the whole thing. So, I ended up just adding some decorations in the menu on the CLI and some dividers to improve clarity. 

Here are some screenshots of the end result!
  
Main menu:   
<img width="308" height="156" alt="Screenshot 2026-07-17 at 19 42 50" src="https://github.com/user-attachments/assets/766d2bea-a5ae-4a25-8d1f-b5b30e592de5" />

Task list:  
<img width="274" height="188" alt="Screenshot 2026-07-17 at 19 43 23" src="https://github.com/user-attachments/assets/6f881f46-c316-4501-99b1-82563a7866b9" />

JSON file:  
<img width="498" height="479" alt="Screenshot 2026-07-17 at 19 43 44" src="https://github.com/user-attachments/assets/c6e7fa5f-c1ea-4081-a034-8870e7f63b9f" />  


   
In the end, I am very proud for learning how to manage files in C++ and also figuring out Codespaces, since up until that point I was only using PyCharm. 
Note to self: do NOT assume I can learn C++ in a day

**AI:** I used it to explain the error in my code when I was debugging and couldn't figure out what was wrong by myself or couldn't find a clear or working answer in any forums.

### *How to run the program*
1. Clone the repository  
Run this in your terminal (Github Codespaces or Linux systems): git clone  
cd /workspaces/Task-manager/src/

3. Install the library (so the C++ code can use the JSON library)  
Run: sudo apt install nlohmann-json3-dev
  
4. Compile  
Run: g++ logic.cpp -o task-manager
  
5. Run!  
Run: ./task-manager  

Long process cause C++ refuses to cooporate. Don't ask me why I chose this language. :P

That's all!

xx Nomeda
