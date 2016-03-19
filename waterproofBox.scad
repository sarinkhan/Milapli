

insideBoxMinX=80;
insideBoxMinY=60;
insideBoxMinZ=40;

insideBoxX1=insideBoxMinX+0;
insideBoxY1=insideBoxMinY+0;
insideBoxZ1=insideBoxMinZ+0;

boxWallsThickness1=1;
boxSealingLipWidth=10;

module fixationPillar(pillarWidth=5,pillarHeight=insideBoxMinZ,pillarScrewRadius=3/2)
{
    difference()
    {
    cube([pillarWidth,pillarWidth,pillarHeight]);
        translate([pillarWidth/2,pillarWidth/2,1])
        cylinder(r=pillarScrewRadius,h=pillarHeight,$fn=12);
    } 
}

module topOpenedBox(insideBoxX=insideBoxX1,insideBoxY=insideBoxY1,insideBoxZ=insideBoxZ1,boxWallsThickness=boxWallsThickness1)
{
//bottom plate
cube([insideBoxX,insideBoxY,boxWallsThickness]);


//back plate
translate([-boxWallsThickness,-boxWallsThickness,0])
cube([boxWallsThickness,insideBoxY+boxWallsThickness*2,insideBoxZ+boxWallsThickness]);

//front plate
translate([insideBoxX,-boxWallsThickness,0])
cube([boxWallsThickness,insideBoxY+boxWallsThickness*2,insideBoxZ+boxWallsThickness]);

//left plate
translate([0,-boxWallsThickness,0])
cube([insideBoxX,boxWallsThickness,insideBoxZ+boxWallsThickness]);

//Right plate
translate([0,insideBoxY,0])
cube([insideBoxX,boxWallsThickness,insideBoxZ+boxWallsThickness]);
}

module sealingLidShape(insideBoxX=insideBoxX1,insideBoxY=insideBoxY1,insideBoxZ=insideBoxZ1,boxWallsThickness=boxWallsThickness1,lipWidth=10,lipThickness=2,nbHolesX,nbHolesY,holesRadius=3/2)
{
    translate([0,0,insideBoxZ+boxWallsThickness-lipThickness])
    {
        
        //back
        translate([-lipWidth-boxWallsThickness,-lipWidth-boxWallsThickness,0])
        cube([lipWidth,insideBoxY+lipWidth*2+boxWallsThickness*2,lipThickness]);
        
        //left
        translate([-lipWidth-boxWallsThickness,-lipWidth-boxWallsThickness,0])
        cube([insideBoxX+lipWidth*2+boxWallsThickness*2,lipWidth,lipThickness]);
        
        //front
        translate([insideBoxX1+boxWallsThickness,-lipWidth-boxWallsThickness,0])
        cube([lipWidth,insideBoxY+lipWidth*2+boxWallsThickness*2,lipThickness]);
        
        //right
        translate([-lipWidth-boxWallsThickness,insideBoxY+boxWallsThickness,0])
        cube([insideBoxX+lipWidth*2+boxWallsThickness*2,lipWidth,lipThickness]);
        
        
    } 
}



sealingLidShape();
topOpenedBox();
