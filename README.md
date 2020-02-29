# ROOT MVP GUI

Program demonstrates a simple implementation of the Model-View-Presenter (MVP) architectural pattern in the CERN ROOT framework.

<img src="http://petrstepanov.com/static/screenshot-root-mvp-gui.png" alt="Implementation of the MVP architectural pattern in the CERN ROOT user interface" style="width: 100%;"/>

The interface consists of a single **View** with an input field and two buttons. Input field's value is the only value stored in the **Model**. Two buttons are used to save and load the view state. The workflow of the program is following:
* Due to the user interaction the input field attached to the **View** changes its value.
* **View** sends the signal to the Presenter; upon receiving the notification **Presenter** passes the input field value to the *Model**.
* The **Model** saves correspondent value in a data structure and emits the success signal back to the **Presenter**.
* **Presenter** triggers the update of the View's state; **View** reflects the updated value of the input field.
* Additionally, **Model** has capabilities of writing and reading its data structure to a local ROOT file on the hard drive. This allows saving and restoring different states of  the application.

## Installation on Windows 10

1. Install Ubuntu linux inside Windows Subsystem for Linux (WSL) as described [here](https://medium.com/@petrstepanov/installing-cern-root-in-windows-subsystem-for-linux-wsl-e83533a10a18).

2. Open _Start → Ubuntu_ to launch linux Terminal. Proceed with Installation on Linux below.

P.S. Running the program on older versions of Windows is currently not possible. If you are familiar with CMAKE please contribute :-) 

## Installation on Linux or macOS

1. Install CERN ROOT on your system. Details can be found [here](https://medium.com/@petrstepanov/install-cern-root-roofit-on-macos-and-linux-for-dummies-df787fd41ef4).

2. Open your Terminal and clone the program folder on your hard drive:

```
mkdir -p ~/Downloads && cd ~/Downloads
git clone https://github.com/petrstepanov/root-mvp-gui
cd ./root-mvp-gui
```

3. Compile the source code and link with ROOT libraries into a binary executable:
```
make
make install
```
4. In order to launch the application type `root-mvp-gui` in Terminal.

5. Optionally add an application launcher to the list of your system apps. On Linux execute `make install-linux-launcher`.

---

Shoot me an email with feedback or questions: [petrs@bgsu.edu](mailto:petrs@bgsu.edu)