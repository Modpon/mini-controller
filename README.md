# Mini Controller

![Alt text](https://raw.githubusercontent.com/Modpon/mini-controller/master/images/mini-modpon-controller-v1.jpg "The first build of the mini controller")

<p>This tiny controller simply turns a 3-5v pump on and off. The duration of the times is set in the Arduino code. By default the pump will turn on every hour for 1 minute. You can modify this if you need to by connecting the controller to your pc.</p>

<h2>What you need</h2>
<ul>
<li>Arduino Nano</li>
<li>6v Pump</li>
<li>USB cable (normal and mini connector)</li>
<li>PC (Windows, MAC or Linux)</li>
<li>Soldering (or prototype) board</li>
<li>10k Resistor</li>
<li>10uF Condensator</li>
<li>Transistor BC547 (up to 100mA)</li>
<li>Block connector (to connect pump to board)</li>
<li>Few wires</li>
</ul>

<h2>Building the hardware part of the controller</h2>
<p>The easiest way to power and control the pump is with an Arduino Nano. Of course other options are plentyfull and out there but the Arduino Nano is cheap, small and easy to program.</p>
<p>The Arduino runs on 5v, this is enough to power a small pump and water the plants. The power comes from anything that can power a USB device, like a computer, TV or a wall plug.</p>
<p>Take a look at the schema below and solder the components to a board. Use a prototype board or even some card board to keep everything together. It's a good idea to put everything in a waterproof case, just in case water spills. Modpon has created a small circuit board which is easy to solder and fits nicely in a small case.</p>

![Alt text](https://raw.githubusercontent.com/Modpon/mini-controller/master/images/Arduino-nano-mini-pump-schema.png "The arduino nano mini controller schema")

<h2>Programming the Arduino controller</h2>
<p>The Arduino is also very easy to program, just download the free sotware (IDE) on <a title="Download the Arduino IDE" href="http://arduino.org/downloads" target="_blank">Arduino.org and install it.</a></p>
<p>Now let's get started</p>

<ol>
<li>Plug a USB cable into your PC and the Arduino.</li>
<li>Start the IDE and check if it connected, go to <strong>Tools</strong> -&gt; <strong>Serial Port</strong> and check if the device is checked. If <strong>Serial Port</strong> is greyed out nthe connection failed, try connecting the USB cable again, another USB port or another cable.</li>
<li>Select the Arduino your using under <strong>Tools</strong> -&gt; <strong>Board</strong> -&gt; <strong>Arduino Nano w/ATmega328</strong> (or a different one your using)</li>
<li>Use one of the two controller codes and <strong>copy</strong> the code.

<p><a href="https://github.com/Modpon/mini-controller/blob/master/basicController.ino" target="blank">Basic time delay code.</a> Use this if it's your first time using Arduino code.</p>
<p><a href="https://github.com/Modpon/mini-controller/blob/master/pumpMiniController.ino" target="blank">Less basic without a delay in the loop.</a> This one is a litte bit more complicated and uses Unsigned long variables instead of a time Delay.</p>

</li>
<li>Back in your IDE <strong>paste</strong> the code. Make any changes you want, like pin number or timing intervals. Read the comments in the code to see what the conbtroller actually does. <strong>SAVE the sketch</strong> somewhere on your PC.</li>
<li>F. Now click the <strong>Upload icon</strong> (right arrow), or go to <strong>File</strong> -&gt; <strong>Upload</strong> and check the bottom part of the IDE should now show messages when compiling and uploading the code to the Arduino. The TX and RX LED's (on the Arduino Nano) should flicker and the IDE will notify you when the code is succesfully uploaded.</li>
</ol>

<h2>Final Steps</h2>
<p>Connect the controller and pump, make sure you have plus (red) and ground (black) wires connected correctly. The USB will provide all the power.</p>
<p>Connect the usb to some sort of power source and the pump will start running!</p>


<h2>Build a window sill hydroponics stand</h2>
<p>The controller you just created is perfect for small setups like the window bottle stand.</p>
<p>The complete build for this is coming soon!</p>
![Alt text](https://raw.githubusercontent.com/Modpon/mini-controller/master/images/window-sill-4bottled-plants-sketch.png "the mini controller in a window sill setup")