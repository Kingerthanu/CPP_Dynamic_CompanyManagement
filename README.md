# CPP_Dynamic_CompanyManagement
This Program Works to Create Dynamic Deep Hierachies Between Varying Interlinked Objects Using Principles of Programming-by-Contract, Rule-of-5, Data-Batching, Using a Practical Design Model, As Well As Contractual Data Sharing/Transferring of Companies and Their Management of Associated Teams and Employees in Order To Create A Robust CodeBase (revolutionary ik).

This Program Basically Boils Down to The Comparison Relation Between Skills of Either a Employee and a Task to Estimate The Execution Time of Task Based Upon Their Skill Differences For Shared Skills. A Employee Will Be Granted Proficiency In a Skill Either During It's Hiring Process (Initialization) or By Doing Tasks, and Learning From Doing Their Associated Skills. All These Skills Will Also Be Stored In a New Object Coined SkillSet Which Work as a Container Class, Holding All Associated Skills For Either a Task or Employee (This is Unique For Our C++ Iteration of This and Isn't In Our <a href="https://github.com/Kingerthanu/CSharp_CompanyManagement">C# Port</a>). This Means if a Task uses Skill 1 and Employee Doesn't Have Skill 1 in its SkillSet, They Will Take Longer To Complete The Task, But Will Gain Some Proficiciency in it For Having Done Something Related to it (First Sight of A Skill Through A Task Will Start That Employee At Proficiency Level-1 For That Skill Always). After This Initial Sighting of The Skill, Proficiency Then Will Be Added In a Scale Where More Difficult Skills Will Give More Proficiency Than Easier Ones. This Process is Expanded Upon Through The Usage of Teams, in Which Will Hold Many Employees. These Employees on The Team Will Work Together in Groups (scalable [have it at groups of 4 right now]) to Complete the Task Quicker By Dividing Out Sub-Tasks to Each. Each Teammate/Employee Will Then Still Be Benefitted By Proficiency Gains. Teams Will Be Held Inside a Company Class Which Will Work to Manage Their States and Works as Means of a Interface to Work With its internal Teams, and Associated Employees. The Company Allows Easy Containment of Associated Teams and Employees by Employing Hiring Functionality as well as Team Creation Functionality For The End-User. Other Than The Real Functionality, This C++ Iteration Also Includes a Inclusion of Move Semantics as Well as Deep and Shallow Copying of Specified Members To Make Sure Data Transfer is Sound (And Known) Throughout Instances. Other Than These Operands, We Also Include Some Other Intuitive Operands For SkillSets in Order To Allow The User To Use Intuitive Design in Their Usage of SkillSet(s). Using This Structure, We Commit Many Unit Tests and Integration Tests Using Microsoft's Provided TestCase Library to Ensure Lavish Branch and Line Coverage of All Our Code. The Provided Version Also Includes The Utilization of the Moq Library for Moq Testing (in the code there may be some bloat for these Moq's to Work Properly).

<img src="https://media.giphy.com/media/5r5J4JD9miis/giphy.gif" alt="Blender + Fork = Yummers" width="320" height="190">

This Program Taught Me A Lot More About Data-Handling; I Created This Program Using A Ping-Pong Learning Strategy By Creating One Chunk of The Code in C#, then ported it quite 1:1 to C++. Then From C++ Back to C#. This Program Taught Me Extensively About The Applications of the std::ptrs (std::unique_ptr<>, std::shared_ptr<>, std::weak_ptr<>) and How They're Applied Practically In Some Instances. While I Made It a Challenge For Myself To Use These As Extensively and Broadly As Possible, I Did Accomplish My Goal Of Understanding These Types But At What Cost? Hours of My Nights Slaved To The StackOverflow Lords? Well.. Yeah. I Really Didn't See The Benefits This Gave Me Until I Finshed The Program, But It Did Teach Me A Lot About How Data Is Moved Around In Less Expected Ways Than You May Think On The Surface.

<img src="https://media.giphy.com/media/7A1ZCMkDzxYp1HoJoO/giphy.gif" alt="Blender + Fork = Yummers" width="320" height="490">

 I learned A LOT About Move Semantics And Actually See New Applications of It In Future Projects As I Inferred References Were As Best As We Could Get. I Also Learned A Lot About Proper Contract-Derived Input/Output Sanitization Like In Copy Operators and Our Banking On Our Contracts Being Upheld In Order To Get Some Exciting Code Written Without Annoying Overhead In Some Edge Cases. I Also Muchhhh More Comfortable With Visual Studios Debugging Tool As I Didn't Use Valgrind Or Any Other External Software So Learned A Lot About BreakPoints And Actually How To Sift Through Our Code (Mainly If We Have Reoccuring Code) For Bugs Or Leaks.
 
<img src="https://media.giphy.com/media/eiLCRSxfO0zymHHecI/giphy.gif" alt="Blender + Fork = Yummers" width="420" height="290">
