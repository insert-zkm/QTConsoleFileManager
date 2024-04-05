# QTConsoleFileManager

## Task Description

Write a console-based program that monitors selected files and reports changes in their state.

We will focus on two characteristics for tracking changes:

1. File existence.
2. File size.

The program will output notifications to the console about any changes that occur in the file.

There are several scenarios for the observed file:

1. File exists and is not empty - a notification is displayed about the existence of the file and its size.
2. File exists and has been modified - a notification is displayed about the existence of the file, a message indicating that the file has been modified, and its new size.
3. File does not exist - information is displayed that the file does not exist.

When a change in the state of the observed file occurs (an event occurs), the corresponding message should be displayed on the screen.

In this implementation, we use the signal-slot connection mechanism to ensure the handling of the observed file change events.

## Test cases
- check if tracking file contains only once

## UML of lab
![Class Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/insert-zkm/QTConsoleFileManager/dev/UML/instance.puml)
