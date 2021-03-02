from datetime import datetime
import pyperclip


def file_name():
    name = input('Name of file: ')
    return name


def assignmentType():
    return input('Lab or Project?: ')


def assignment():
    assignment = input('Name of assignment: ')
    return assignment


def date():
    currentdate = datetime.now()
    return currentdate.strftime('%m/%d/%Y')


def description():
    description = input('Description: ')
    return description


if __name__ == '__main__':
    name = file_name()
    assignment = assignment()
    assignmentType = assignmentType()
    date = date()
    description = description()
    header = f"""
/*******************************************************************
** File: {name} 
** {assignmentType}: CMSC 202 {assignment}, Spring 2021
** Author: Luke Gude
** Date: {date}
** Section: 10/12
** E-Mail: lgude1@umbc.edu
**
** {description}
*******************************************************************/
    """
    # print(header)
    pyperclip.copy(header)
