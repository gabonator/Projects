//
//  ViewController.swift
//  SwiftGoose
//
//  Created by Gabriel Valky on 12/25/20.
//

import UIKit

class ViewController: UIViewController {
    var timerGame: Timer? = nil
    var timerSound: Timer? = nil
    let goose = GooseWrapper()
    @IBOutlet weak var image: UIImageView!
    var lastFreq: Int32 = 0
    let toneOutput = ToneOutput()
    var toneTimeout = 0
    
    override var shouldAutorotate: Bool {
        return true
    }
    
    override func viewDidLoad() {
        let value = UIInterfaceOrientation.landscapeLeft.rawValue
        UIDevice.current.setValue(value, forKey: "orientation")
        
        super.viewDidLoad()
        
        goose.initApp()
        
        self.timerGame = Timer.scheduledTimer(timeInterval: 0.03, target: self, selector: #selector(self.onTimerGame), userInfo: nil, repeats: true)
        self.timerSound = Timer.scheduledTimer(timeInterval: 0.02, target: self, selector: #selector(self.onTimerSound), userInfo: nil, repeats: true)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let allTouches = event?.allTouches else { return }
        
        for touch in allTouches {
            let touchPoint = touch.location(in: self.image)
            let px = Int32(touchPoint.x / self.image.frame.width * 320)
            let py = Int32(touchPoint.y / self.image.frame.height * 200)
            if px > 20 && px < 320-20 && py > 100 {
                goose.setPosition(px)
            }
        }
    }

    @objc func onTimerGame(_ timer: Timer) {
        goose.run()
        image.image = imageFromRGBBitmap( data:goose.getImageData(), width:320, height:200)
    }

    @objc func onTimerSound(_ timer: Timer) {
        goose.sound();
        let freq = goose.getPlayFrequency()
        if freq != lastFreq {
            if freq > 0 {
                toneOutput.setFrequency(freq: Double(freq))
                toneOutput.setToneVolume(vol: 0.5)
                toneOutput.enableSpeaker()
                toneOutput.setToneTime(t: 300)
                toneTimeout = 5
            } else {
//                toneOutput.stop()
            }
            lastFreq = freq
        }
        if freq == 0 && toneTimeout > 0 {
            toneTimeout -= 1
            if toneTimeout == 0 {
                toneOutput.stop()
            }
        }
    }

    private func imageFromRGBBitmap(data: Data, width: size_t, height: size_t) -> UIImage? {
        let bitsPerComponent: size_t = 8
        let bitsPerPixel: size_t = 24
        let rgbColorSpace = CGColorSpaceCreateDeviceRGB()
        let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue)
            .union(.byteOrder32Little)
        
        let providerRef:CGDataProvider = CGDataProvider(data: data as CFData)!

        let cgImage:CGImage? = CGImage(width: width, height: height, bitsPerComponent: bitsPerComponent, bitsPerPixel: bitsPerPixel, bytesPerRow: width * 3, space: rgbColorSpace, bitmapInfo: bitmapInfo, provider: providerRef, decode: nil, shouldInterpolate: true, intent: .defaultIntent)
        
        guard let cgImage2 = cgImage else {
            assertionFailure()
            return nil;
        }
        return UIImage(cgImage: cgImage2)
    }
}

extension ViewController
{
    @IBAction func leftMissile(_ sender: Any) {
        goose.pressKey(49)
    }
    @IBAction func leftMissileUp(_ sender: Any) {
        goose.releaseKey(49)
    }
    @IBAction func rightMissile(_ sender: Any) {
        goose.pressKey(50)
    }
    @IBAction func rightMissileUp(_ sender: Any) {
        goose.releaseKey(50)
    }
    @IBAction func leftDown(_ sender: Any) {
        goose.pressKey(57)
        //goose.pressKey(75)
    }
    @IBAction func leftUp(_ sender: Any) {
        goose.releaseKey(57)
        //goose.releaseKey(75)
    }
    @IBAction func rightDown(_ sender: Any) {
        goose.pressKey(57)
        //goose.pressKey(77)
    }
    @IBAction func rightUp(_ sender: Any) {
        goose.releaseKey(57)
        //goose.releaseKey(77)
    }
}
