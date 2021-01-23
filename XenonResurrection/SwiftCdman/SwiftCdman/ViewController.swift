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
    let cdman = CdmanWrapper()
    @IBOutlet weak var image: UIImageView!
    //var lastFreq: Int32 = 0
    //let toneOutput = ToneOutput()
    var toneTimeout = 0
    
    override var shouldAutorotate: Bool {
        return true
    }
    
    override func viewDidLoad() {
        let value = UIInterfaceOrientation.landscapeLeft.rawValue
        UIDevice.current.setValue(value, forKey: "orientation")
        
        super.viewDidLoad()
        
        cdman.initApp()
        
        self.timerGame = Timer.scheduledTimer(timeInterval: 0.03, target: self, selector: #selector(self.onTimerGame), userInfo: nil, repeats: true)
        //self.timerSound = Timer.scheduledTimer(timeInterval: 0.02, target: self, selector: #selector(self.onTimerSound), userInfo: nil, repeats: true)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let allTouches = event?.allTouches else { return }
        
        for touch in allTouches {
            let touchPoint = touch.location(in: self.image)
            let px = Int32(touchPoint.x / self.image.frame.width * 640)
            let py = Int32(touchPoint.y / self.image.frame.height * 350)
            cdman.setPosition(px, y:py);
            break;
        }
    }

    @objc func onTimerGame(_ timer: Timer) {
        cdman.run()
        image.image = imageFromRGBBitmap( data:cdman.getImageData(), width:640, height:350)
    }

    //@objc func onTimerSound(_ timer: Timer) {
    //}

    private func imageFromRGBBitmap(data: Data, width: size_t, height: size_t) -> UIImage? {
        let bitsPerComponent: size_t = 8
        let bitsPerPixel: size_t = 32
        let rgbColorSpace = CGColorSpaceCreateDeviceRGB()
        let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.noneSkipLast.rawValue)
            .union(.byteOrder32Big)
        
        let providerRef:CGDataProvider = CGDataProvider(data: data as CFData)!

        let cgImage:CGImage? = CGImage(width: width, height: height, bitsPerComponent: bitsPerComponent, bitsPerPixel: bitsPerPixel, bytesPerRow: width * 4, space: rgbColorSpace, bitmapInfo: bitmapInfo, provider: providerRef, decode: nil, shouldInterpolate: false, intent: .defaultIntent)
        
        guard let cgImage2 = cgImage else {
            assertionFailure()
            return nil;
        }
        return UIImage(cgImage: cgImage2)
    }
}
