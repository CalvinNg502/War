# War

## Table of Contents
- [Introduction](#introduction)
- [Launch](#launch)
- [Features](#features)
- [Status](#status)

## Introduction

This repository stores a C++ implementation of the card game 'War.' This project was developed Spring, 2022, for CSC 340 at UNCG. The goal was to work with an object-oriented project in C++.

This is a console program, meaning there is no gui and the player interacts with the game through text input and output from a shell. For the rules of war, see [this link](https://bicyclecards.com/how-to-play/war) for the details.

## Launch

The project does not need any non-standard C or C++ libaries. 

This project was developed in the Visual Studio IDE, and it was tested and ran in Visual Studio's runtime environment. So, it is recommended that other users should do the same. The .c++ and .h files are present, however, so this is not necessary; the user may run the project without Visual Studio should they desire by employing any method they prefer that functions given these files.

## Features

Here is a short overview of features this project includes:
- Abstracts individual cards and decks of cards
- Abstracts deck behaviors, such as drawing cards, putting cards on the bottom of decks, and shuffling decks.
- Implements turn behavior that alternates between the computer and the player.
- Handles player input and displays appropriate output depending on which cards are drawn.
- Recognizes victory conditions and ends the game.

## Status

This project was completed and fully implements a game of war in accordance to the rules linked above. There is room for improvement, of course, such as implementing a gui or implementing different variations of the game, but this project is considered concluded; it is highly unlikely that this repository will be updated again.