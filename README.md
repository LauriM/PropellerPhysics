# PropellerPhysics

Experimental 2D physics engine written in C++.

## Planning

Some ideas for the object model inside the physics engine.

           shape
    	^   ^      ^
    Circle  Plane  Box



    Object
       -> Shape
    		-> Collision Data
       -> vel
       -> pos


Object model seems like a better option, data like velocities and positions are kept local, while Collision Data can be changed.