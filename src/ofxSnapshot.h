#ifndef OFXSNAPSHOT_H_
#define OFXSNAPSHOT_H_

/** TODO
 * selection via mouse
 * grab screen
 * save snapshot from ofImage
 * */

#include "ofMain.h"

class ofxSnapshot {
public:
	ofxSnapshot();
	virtual ~ofxSnapshot();

	void setSnapshotKey(char key);

	ofColor color;
	virtual void draw();

	virtual void keyPressed(ofKeyEventArgs & e);
	virtual void keyReleased(ofKeyEventArgs & e){}

	virtual void mousePressed(ofMouseEventArgs &e);
	virtual void mouseDragged(ofMouseEventArgs &e);
	virtual void mouseReleased(ofMouseEventArgs &e);
	virtual void mouseMoved(ofMouseEventArgs &e){}
protected:
	char snapshotKey;
	bool snapshotActive, isMousePressed;
	ofPoint tl,br;
	ofImage snapshot;
};

#endif /* OFXSNAPSHOT_H_ */
